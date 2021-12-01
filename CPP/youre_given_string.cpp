#include <iostream>
#include <iterator>
#include <map>

using namespace std;

/*
https://codeforces.com/problemset/problem/23/A
*/

bool is_slide_window_ok(string str, int slide_window) {
	int str_len = str.length();

	// window is larger than str len, cannot slide
	if (slide_window >= str_len) {
		return false;
	}

	string slide_substr = "";
	string iter_substr = "";

	for (int i = 0; i + slide_window - 1 < str_len; i++) {
		slide_substr = str.substr(i, slide_window);

		int slide_first = i + 1;
		for (int j = slide_first; j + slide_window - 1 < str_len; j++) {
			iter_substr = str.substr(j, slide_window);

			if (slide_substr == iter_substr) {
//				cout << slide_window << endl;
				return true;
			}
		}
	}

	return false;
}

int detect_twice_occur_substr(string str) {
	int slide_window = str.length();

	while (true) {
		if (slide_window == 0) {
			return 0;
		}

		if (is_slide_window_ok(str, slide_window)) {
			return slide_window;
		}

		slide_window --;
	}

	return 0;
}

int main() {
	string str;

	cin >> str;

//	string a = "A";
//	string b = "A";
//
//	cout << (a == b) << endl;

	int max_sublen = detect_twice_occur_substr(str);
	if (max_sublen) {
		cout << max_sublen << endl;
		return 0;

	}

	cout << 0 << endl;
	return 0;
}









