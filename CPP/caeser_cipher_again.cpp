#include <bits/stdc++.h>
using namespace  std;


/*
https://atcoder.jp/contests/abc232/tasks/abc232_b
*/


int main() {
	string s, t;

	cin >> s;
	cin >> t;

	char s_first = s[0];
	char t_first = t[0];

	int s_first_i = s_first - 'a';
	int t_first_i = t_first - 'a';

	int diff = 0;
	if (s_first_i > t_first_i) {
		// shift t to s
		diff = s_first_i - t_first_i;

		string t_new;
		for (int i = 0; i < t.size(); i++) {
			char a = char((t[i] - 'a' + diff) % 26 + 'a');
//			cout << a << endl;
			t_new += a;
		}
//		cout << t_new << endl;
		if (s == t_new) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	} else {
		// shift s to t
		diff = t_first_i - s_first_i;

		string s_new;
		for (int i = 0; i < s.size(); i++) {
			char a = char((s[i] - 'a' + diff) % 26 + 'a');
			s_new += a;
		}

		if (s_new == t) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}