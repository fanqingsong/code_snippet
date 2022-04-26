#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1669/problem/A
*/

int main() {
	int t;

	cin >> t;
	for (int i = 0; i < t; i++) {
		int rating;
		cin >> rating;

		if (rating >= 1900) {
			cout << "Division 1" << endl;
		} else if (rating >= 1600 && rating <= 1899) {
			cout << "Division 2" << endl;
		} else if (rating >= 1400 && rating <= 1599) {
			cout << "Division 3" << endl;
		} else if (rating <= 1399) {
			cout << "Division 4" << endl;
		}
	}
}