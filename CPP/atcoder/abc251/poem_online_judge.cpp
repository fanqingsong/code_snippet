#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;



/*
https://atcoder.jp/contests/abc251/tasks/abc251_c
*/

int main() {
	int n;

	set<string> sset;

	cin >> n;

	int max = -1;
	int max_index = -1;
	for (int i = 0; i < n; i++) {
		string si;
		int ti;

		cin >> si;
		cin >> ti;

		if (sset.count(si) == 0) {
			sset.insert(si);

			if (ti > max) {
				max = ti;
				max_index = i;
			}
		}
	}

	cout << max_index + 1 << endl;
}
