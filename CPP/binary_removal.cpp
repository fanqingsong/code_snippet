#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int w1;
		for (int i = s.size() - 2; i >= 0; i--) {

			if (s[i] == '0' && s[i + 1] == '0') {
				w1 = i;
				break;
			} else if (i == 0) {
				cout << "yes" << endl;
				goto away;
			}
		}
		int w2;
		for (int i = 0; i < s.size() - 1; i++) {

			if (s[i] == '1' && s[i + 1] == '1') {
				w2 = i;
				break;
			} else if (i == s.size() - 2) {
				cout << "yes" << endl;
				goto away;
			}
		}

//		cout << (w1) << endl;
//		cout << (w2) << endl;

		if (w1 < w2) {
			cout << "yes" << endl;
			continue;
		} else {
			cout << "no" << endl;
			continue;
		}
away:
		;
	}
}