#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc249/tasks/abc249_b
*/


int main() {
	string s;

	cin >> s;

	int size = s.size();

	bool upper_flag = false;
	bool lower_flag = false;
	map<char, int> counter;

	for (int i = 0; i < size; i++) {
		char temp = s[i];
		if (temp >= 'A' && temp <= 'Z') {
			upper_flag = true;
		} else if (temp >= 'a' && temp <= 'z') {
			lower_flag = true;
		}

		int num = counter[temp];
		if (num > 0) {
			cout << "No" << endl;
			return 0;
		} else {
			counter[temp] ++;
		}
	}

	if (upper_flag && lower_flag) {
		cout << "Yes" << endl;
		return 0;
	}

	cout << "No" << endl;

	return 0;
}


