#include <iostream>
#include <stdlib.h>     /* abs */
using namespace std;

/*
http://codeforces.com/problemset/problem/1607/A
*/

struct ITEM {
	string keyboard;
	string input;
};

int find_pos(char one_char, string str) {
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (one_char == str[i]) {
			return i;
		}
	}

	return -1;
}

int main() {
	int count;
	struct ITEM data[50];

	cin >> count;

	for (int i = 0; i < count; i++) {
		cin >> data[i].keyboard;
		cin >> data[i].input;
	}

	for (int i = 0; i < count; i++) {
		int distance = 0;
		int inputlen = data[i].input.size();
		string keyboard = data[i].keyboard;

		for (int j = 0; j < inputlen - 1; j++) {
			char first = data[i].input[j];
			char second = data[i].input[j + 1];

			int first_pos = find_pos(first, keyboard);
			int second_pos = find_pos(second, keyboard);

			distance += abs(first_pos - second_pos);
		}

		cout << distance << endl;
	}
}

