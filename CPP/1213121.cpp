#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <deque>
#include <string>
using namespace std;


/*
https://atcoder.jp/contests/abc247/tasks/abc247_c
*/

string get_reverse(int n) {
	if (n == 1) {
		return "1";
	}

	string lower_reverse = get_reverse(n - 1);
	string now_reverse = lower_reverse + " " + to_string(n) + " " + lower_reverse;

	return now_reverse;
}

int main() {
	int N;

	cin >> N;

	string ret = get_reverse(N);

	cout << ret << endl;

	return 0;
}

