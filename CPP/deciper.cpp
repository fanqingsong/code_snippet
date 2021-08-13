#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
	string securedkey;
	string decipheredkey;

	cout << "please input your secured key:" << endl;
	getline(cin, securedkey);

	cout << "the possible deciphered key:" << endl;
	for (int i = 1; i <= 25; i++) {
		cout << "backward step=" << i << ": ";

		decipheredkey.clear();

		// a-yz -> b-za for 1 step forward
		// 1 step backward: b-za -> a-yz
		// 2 step backward: c-zab -> a-xyz
		for (int j = 0; j < securedkey.length(); j++) {
			char c = securedkey.at(j);

			// b-z part, move back
			char high_backward = 'z';
			char low_backward = 'z' - 26 + i;

			// a part, move forward
			char high_forward = 'a' + i - 1;
			char low_forward = 'a';

			char aim = '?';

			if (c <= high_backward && c >= low_backward) {
				aim = c - i;
			} else if (c <= high_forward && c >= low_forward) {
				aim = c + 26 - i;
			} else {
				aim = c;
			}

			decipheredkey.push_back(aim);
		}

		cout << decipheredkey << endl;
	}

	return 0;
}
