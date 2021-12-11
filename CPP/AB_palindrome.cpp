#include <iostream>
using namespace std;

/*
https://codeforces.com/problemset/problem/1512/C
*/

struct TestCase {
	string str;
	int a;
	int b;
};

bool is_palindrome_possible(string &str, int a, int b) {
	int len = str.size();

	if (a + b != len) {
//		cout << "a + b != len" << endl;
		return false;
	}

	int counta = 0;
	int countb = 0;

	// pre count the num of 0 and 1
	for (int i = 0; i < len; i++) {
		if (str[i] == '0') {
			counta++;
		} else if (str[i] == '1') {
			countb ++;
		}
	}

	if (len % 2 == 1) {
		int middle = len / 2;

		if (str[middle] == '?') {
			if (a % 2 == 1) {
				str[middle] = '0';
				counta ++;
			} else if (b % 2 == 1) {
				str[middle] = '1';
				countb ++;
			}
		}
	}

	for (int i = 0; i < len / 2; i++) {
		char left = str[i];
		char right = str[len - i - 1];
		int left_index = i;
		int right_index = len - i - 1;

		if (left == '0') {
			if (right == '0') {
			} else if (right == '?') {
				str[right_index] = '0';
				counta++;
			} else if (right == '1') {
//				cout << "left right not match." << endl;
				return false;
			} else {
//				cout << "right char invalid." << endl;
				return false;
			}
		} else if (left == '1') {
			if (right == '1') {
			} else if (right == '?') {
				str[right_index] = '1';
				countb++;
			} else if (right == '0') {
//				cout << "left right not match." << endl;
				return false;
			} else {
//				cout << "right char invalid." << endl;
				return false;
			}
		} else if (left == '?') {
			if (right == '0') {
				str[left_index] = '0';
				counta++;
			} else if (right == '1') {
				str[left_index] = '1';
				countb++;
			} else if (right == '?') {
				if (a - counta >= 2) {
					str[left_index] = '0';
					str[right_index] = '0';
					counta++;
					counta++;
				} else if (b - countb >= 2) {
					str[left_index] = '1';
					str[right_index] = '1';
					countb++;
					countb++;
				} else {
					// do nothing
				}
			} else {
//				cout << "right char invalid." << endl;
				return false;
			}
		} else {
//			cout << "left char invalid." << endl;
			return false;
		}
	}

	if (a == counta && b == countb) {
		return true;
	}

	return false;
}

int main() {
	int total = 0;

	TestCase tc[10000];

	cin >> total;
	for (int i = 0; i < total; i++) {
		cin >> tc[i].a;
		cin >> tc[i].b;
		cin >> tc[i].str;
	}

	for (int i = 0; i < total; i++) {
		if (is_palindrome_possible(tc[i].str, tc[i].a, tc[i].b)) {
			cout << tc[i].str << endl;
		} else {
			cout << "-1" << endl;
		}
	}

	return 0;
}



