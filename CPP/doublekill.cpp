#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

vector<string> all_cards;

vector<string> player1_cards;
int player1_bloods = 5;

vector<string> player2_cards;
int player2_bloods = 5;

class RoundResult{
	public:
		string host;
		string guest;
		string host_card;
		string guest_card;
};

vector<RoundResult> rounds_result;

void initialize() {
	cout << "prepare all cards..." << endl;

	for (int i = 0; i < 70; i++) {
		all_cards.push_back("kill");
	}

	for (int i = 0; i < 50; i++) {
		all_cards.push_back("dodge");
	}

	for (vector<string>::iterator it = all_cards.begin(); it != all_cards.end(); ++it) {
		cout << ' ' << *it;
	}
	cout << endl;
}

int get_index_of_target_card(vector<string> &card_set, string target_card) {
	for (int i = 0; i < card_set.size(); i++) {
		string current_card = card_set[i];
		if (current_card == target_card) {
			return i;
		}
	}

	return -1;
}

string draw_one_card_by_index(vector<string> &card_set, int index) {
	int len = card_set.size();

	if (index < 0 || index >= len) {
		return "";
	}

	string card_got = card_set[index];

	card_set.erase(card_set.begin() + index);

	return card_got;
}

string get_one_card_from_all() {
	int len = all_cards.size();
	if (len <= 0) {
		cout << "no more card." << endl;
		return "";
	}

	/* initialize random seed: */
	srand (time(NULL));

	/* generate secret number between 1 and 10: */
	int pos_got = rand() % len;

	string card_got = draw_one_card_by_index(all_cards, pos_got);

	cout << "got one card: " << card_got << endl;
	cout << "number of left card: " << all_cards.size() << endl;

	return card_got;
}

bool dispatch_cards(vector<string> &card_set, int num) {
	int count = 0;
	string one_card;

	cout << "...now dispatch card..." << endl;

	for (int i = 0; i < num; i++) {
		one_card = get_one_card_from_all();
		cout << "got one card: " << one_card << endl;

		if ("" == one_card) {
			cout << "no card now." << endl;
			break;
		}

		card_set.push_back(one_card);
		count++;
	}

	if (num == count) {
		cout << "...dispatch OK..." << endl;
		return true;
	} else {
		cout << "...dispatch failed..., expected num=" << num << " actual num=" << count << endl;
		return false;
	}
}

void init_dispatch_cards() {
	dispatch_cards(player1_cards, 3);
	dispatch_cards(player2_cards, 3);

	cout << "player1 got:" << endl;
	for (int i = 0; i < player1_cards.size(); i++) {
		cout << player1_cards[i] << " ";
	}
	cout << endl;

	cout << "player2 got:" << endl;
	for (int i = 0; i < player2_cards.size(); i++) {
		cout << player2_cards[i] << " ";
	}
	cout << endl;
}

bool have_target_card(vector<string> &card_set, string target_card) {
	for (int i = 0; i < card_set.size(); i++) {
		if (card_set[i] == target_card) {
			return true;
		}
	}

	return false;
}

bool drop_cards(vector<string> &card_set, int num) {
	for (int i = 0; i < num; i++) {
		draw_one_card_by_index(card_set, 0);
	}

	return true;
}

bool update_one_card(vector<string> &card_set) {
	bool is_success = drop_cards(card_set, 1);
	if (!is_success) {
		return false;
	}

	is_success = dispatch_cards(card_set, 1);
	if (!is_success) {
		return false;
	}

	return true;
}

bool drop_one_card(vector<string> &card_set, string target_card) {
	if (!have_target_card(card_set, target_card)) {
		return false;
	}

	int index = get_index_of_target_card(card_set, target_card);
	if (-1 == index) {
		return false;
	}

	draw_one_card_by_index(card_set, index);

	return true;
}

bool host_do_kill_attack(vector<string> &host_card_set) {
	bool is_success = false;

	cout << "host check kill card." << endl;

	is_success = have_target_card(host_card_set, "kill");
	if (!is_success) {
		cout << "host have no kill card, pass." << endl;

		update_one_card(host_card_set);
		return false;
	}

	cout << "host now drop one kill card" << endl;
	drop_one_card(host_card_set, "kill");

	cout << "host now get one new card" << endl;
	is_success = dispatch_cards(host_card_set, 1);
	if (!is_success) {
		cout << "no card to dispatch to host" << endl;
	}

	return true;
}

bool guest_do_dodge_defense(vector<string> &guest_card_set, int &guest_bloods) {
	bool is_success = false;

	cout << "guest check dodge card." << endl;

	is_success = have_target_card(guest_card_set, "dodge");
	if (!is_success) {
		cout << "guest have no dodge card, blood losed one." << endl;
		guest_bloods--;

		return false;
	}

	cout << "guest now drop one dodge card" << endl;
	drop_one_card(guest_card_set, "dodge");

	cout << "guest give dodge card, blood kept." << endl;

	cout << "guest now get one new card" << endl;
	is_success = dispatch_cards(guest_card_set, 1);
	if (!is_success) {
		cout << "no card to dispatch to guest" << endl;
	}

	return true;
}

bool challenge_by_player1() {
	bool is_success = false;

	RoundResult round_result;
	round_result.host = "player1";
	round_result.guest = "player2";
	round_result.host_card = "Pass";
	round_result.guest_card = "Pass";

	is_success = host_do_kill_attack(player1_cards);
	if (!is_success) {
		cout << "host has no kill card to toss." << endl;
		rounds_result.push_back(round_result);
		return false;
	} 

	round_result.host_card = "kill";

	cout << "host want to kill you, come on, give dodge." << endl;

	is_success = guest_do_dodge_defense(player2_cards, player2_bloods);
	if (!is_success) {
		rounds_result.push_back(round_result);

		if (player2_bloods <= 0) {
			return true;
		}

		return false;
	}

	round_result.guest_card = "dodge";

	rounds_result.push_back(round_result);
	return false;
}

bool challenge_by_player2() {
	bool is_success = false;

	RoundResult round_result;
	round_result.host = "player2";
	round_result.guest = "player1";
	round_result.host_card = "Pass";
	round_result.guest_card = "Pass";

	is_success = host_do_kill_attack(player2_cards);
	if (!is_success) {
		cout << "host has no kill card to toss." << endl;
		rounds_result.push_back(round_result);
		return false;
	}

	round_result.host_card = "kill";

	cout << "host want to kill you, come on, give dodge." << endl;

	is_success = guest_do_dodge_defense(player1_cards, player1_bloods);
	if (!is_success) {
		rounds_result.push_back(round_result);

		if (player1_bloods <= 0) {
			return true;
		}

		return false;
	}

	round_result.guest_card = "dodge";

	rounds_result.push_back(round_result);

	return false;
}

int main() {
	// prepare all cards
	initialize();

	// initial dispatch
	init_dispatch_cards();

	cout << "now begin..." << endl;

	while (true) {
		bool is_end = false;

		cout << "------------- one round begin ------------" << endl;
		is_end = challenge_by_player1();
		cout << "------------- one round end ------------" << endl;

		if (is_end) {
			break;
		}

		cout << "------------- one round begin ------------" << endl;
		is_end = challenge_by_player2();
		cout << "------------- one round end ------------" << endl;

		if (is_end) {
			break;
		}
	}

	cout << "bloods of player1 vs player2:" << endl;
	cout << player1_bloods << ":" << player2_bloods << endl;

	for(int i=0; i<rounds_result.size(); i++){
		RoundResult& round_result = rounds_result[i];
		string host = round_result.host;
		string guest = round_result.guest;
		string host_card = round_result.host_card;
		string guest_card = round_result.guest_card;

		cout << "round: " << i << " |host:" << host << " |guest:" << guest << " |host card:" << host_card << " |guest card:" << guest_card << endl;
	}
}
