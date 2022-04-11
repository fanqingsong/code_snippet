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


	return 0;
}

