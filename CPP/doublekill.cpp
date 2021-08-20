#include <iostream>
#include <vector>
#include <algorithm>    // std::shuffle
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

vector<string> all_cards;

vector<string> player1_cards;
int player1_bloods = 5;

vector<string> player2_cards;
int player2_bloods = 5;


void initialize() {
	cout << "prepare all cards..." << endl;

	for (int i = 0; i < 50; i++) {
		all_cards.push_back("kill");
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
	for (auto it : player1_cards) {
		cout << it << " ";
	}
	cout << endl;

	cout << "player2 got:" << endl;
	for (auto it : player2_cards) {
		cout << it << " ";
	}
	cout << endl;
}

bool have_target_card(vector<string> &card_set, string target_card) {
	for (auto it : card_set) {
		if (it == target_card) {
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

bool fight_one_round(vector<string> &host_card_set, vector<string> &guest_card_set, int &guest_bloods) {
	bool is_success = false;

	cout << "------------- one round begin ------------" << endl;

	cout << "host check kill card." << endl;
	if (!have_target_card(host_card_set, "kill")) {
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
		return true;
	}

	cout << "host want to kill you, come on, give dodge." << endl;

	cout << "guest check dodge card." << endl;
	if (!have_target_card(guest_card_set, "dodge")) {
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
		return true;
	}

	cout << "------------- one round end ------------" << endl;
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
		is_end = fight_one_round(player1_cards, player2_cards, player2_bloods);
		if (is_end) {
			break;
		}

		is_end = fight_one_round(player2_cards, player1_cards, player1_bloods);
		if (is_end) {
			break;
		}
	}

	cout << "bloods of player1 vs player2:" << endl;
	cout << player1_bloods << ":" << player2_bloods << endl;
}
