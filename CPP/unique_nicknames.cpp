#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <deque>
#include <string>
using namespace std;


/*
https://atcoder.jp/contests/abc247/tasks/abc247_b
*/

int main() {
	int N;
	vector<string> family_names;
	vector<string> given_names;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string fname;
		string gname;

		cin >> fname;
		cin >> gname;

		family_names.push_back(fname);
		given_names.push_back(gname);
	}


	for (int i = 0; i < N; i++) {
		string fname = family_names[i];
		string gname = given_names[i];

		bool fname_conflicted = false;
		bool gname_conflicted = false;

		for (int j = 0; j < N; j++) {
			if (j == i) {
				continue;
			}

			string &one_fname = family_names[j];
			string &one_gname = given_names[j];

			if (fname == one_fname || fname == one_gname) {
				fname_conflicted = true;
			}

			if (gname == one_fname || gname == one_gname) {
				gname_conflicted = true;
			}

			if (fname_conflicted && gname_conflicted) {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "Yes" << endl;

	return 0;
}

