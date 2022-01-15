#include <iostream>
using namespace std;


/*
https://codeforces.com/problemset/problem/81/B
*/

bool is_space_then_digit(string s, int i) {
	if (i >= s.size()) {
		return false;
	}

	if (s[i + 1] != ' ') {
		return false;
	}

	int j = i + 1;
	for (; j < s.size(); j++) {
		if (s[j] != ' ') {
			break;
		}
	}

	if (j >= s.size()) {
		return false;
	}

	if (isdigit(s[j])) {
		return true;
	}

	return false;
}

int get_trailing_space_len(string s, int i) {
	if (i >= s.size()) {
		return 0;
	}

	if (s[i + 1] != ' ') {
		return 0;
	}

	int cnt = 0;
	for (int j = i + 1; j < s.size(); j++) {
		if (s[j] != ' ') {
			break;
		}

		cnt ++;
	}

	return cnt;
}

string tokenize_space_between_num(string s) {
	string ans;

	int i = 0;
	while (i < s.size()) {
		if (isdigit(s[i])) {
			ans += s[i];

			if (is_space_then_digit(s, i)) {
				// use * to replace space
				ans += "*";

				int len = get_trailing_space_len(s, i);

				// skip this digit
				i++;

				// skip all trailing spaces
				i += len;
			} else {
				i++;
			}
		} else {
			ans += s[i];
			i++;
		}
	}

	return ans;
}

string restore_space_between_num(string s) {
	string ans;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*') {
			ans += ' ';
		} else {
			ans += s[i];
		}
	}

	return ans;
}

string delete_unneccesary_space(string s) {
	string ans;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			// skip
		} else  {
			ans += s[i];
		}
	}

	return ans;
}

// for , and ...
string add_standard_space(string s) {
	string ans;

	int j = 0;

	while (j < s.size()) {
		if (s[j] == ',') {
			ans += ", ";
			j++;
		} else if (s[j] == '.') {
			if (j == 0) {
				// skip
			} else {
				if (s[j - 1] == ',') {
					// skip
				} else {
					ans += ' ';
				}
			}

			ans += "...";
			j += 3;
		} else {
			ans += s[j];
			j++;
		}
	}

	return ans;
}

int main() {
	string s;

	getline(cin, s);

//	cout << s;

	string ans;

	ans = tokenize_space_between_num(s);
//	cout << "after tokenize" << endl;
	ans = delete_unneccesary_space(ans);
//	cout << "after delete" << endl;
//	cout << ans << endl;
	ans = add_standard_space(ans);
//	cout << "after add" << endl;
//	cout << ans << endl;
	ans = restore_space_between_num(ans);
//	cout << "after restore" << endl;
	cout << ans;
}