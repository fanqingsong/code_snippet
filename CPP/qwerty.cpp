#include <iostream>

using namespace std;

//https://atcoder.jp/contests/abc218/tasks/abc218_b

int main() {
	int nums[26];
	char chars[32] = {0};

//	char a = 'a';
//	cout << a << endl;
//
//	cout << int(a) << endl;
//
//	cout << char(97) << endl;

	for (int i = 0; i < 26; i++) {
		cin >> nums[i];
		chars[i] = char(96 + nums[i]);
	}

	cout << chars << endl;
}

