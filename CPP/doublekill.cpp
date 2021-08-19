#include <iostream>
#include <list>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

using namespace std;

int main() {
	list<string> kill_cards(50, "kill");
	list<string> dodge_cards(50, "dodge");

	list<string> all_cards;
	all_cards.merge(kill_cards);
	all_cards.merge(dodge_cards);

	for (list<string>::iterator it = all_cards.begin(); it != all_cards.end(); ++it) {
		cout << ' ' << *it;
	}

	// shuffle


}
