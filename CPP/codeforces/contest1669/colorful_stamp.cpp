#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1669/problem/D
*/

int main() {
	int t;

	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		string s;

		cin >> n;
		cin >> s;

		s = "W" + s + "W";

		bool blue_flag = false;
		bool red_flag = false;
		bool watching = false;
		bool broken = false;

		for (int j = 0; j < n + 2; j++) {
			char one_color = s[j];

			if (!watching && one_color != 'W') {
				watching = true;
			}

			if (watching && one_color == 'W') {
				if (!(blue_flag && red_flag) ) {
					cout << "No" << endl;
					broken = true;
					break;
				}

				blue_flag = false;
				red_flag = false;

				watching = false;
			}

			if (watching) {
				if (one_color == 'R') {
					red_flag = true;
				} else if (one_color == 'B') {
					blue_flag = true;
				}
			}
		}

		if (!broken) {
			cout << "Yes" << endl;
		}
	}
}