#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc251/tasks/abc251_a
*/

int main() {
	string s;

	cin >> s;

	int size = s.size();
	int times = 6 / size;

	string ans = "";
	for (int i = 0; i < times; i++) {
		ans += s;
	}

	cout << ans << endl;
}