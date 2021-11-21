#include <iostream>
using namespace std;

/*
https://atcoder.jp/contests/abc228/tasks/abc228_a
*/

int main() {
	int s, t, x;
	cin >> s >> t >> x;
//
//	if (!(s >= 0 && s <= 23)) {
//		cout << "S is error." << endl;
//		return -1;
//	}
//
//	if (!(t >= 0 && t <= 23)) {
//		cout << "T is error." << endl;
//		return -1;
//	}
//
//	if (!(x >= 0 && x <= 23)) {
//		cout << "X is error." << endl;
//		return -1;
//	}
//
//	if (s == t) {
//		cout << "S cannot be same as T" << endl;
//		return -1;
//	}

	//   0 ... s ... t ... 23
	if (s < t) {
		if (x >= s && x < t) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
		//   0 ... t ... s ... 23
	} else {
		if (x >= s || x < t) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
