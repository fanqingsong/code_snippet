#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <deque>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc248/tasks/abc248_d
*/

int main() {
	int N;
	map<int, set<int>> gp;

	int Q;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		gp[temp].insert(i);
	}

	cin >> Q;

	for (int i = 0; i < Q; i++) {
		int L, R, X;
		cin >> L >> R >> X;

		set<int> &index_list = gp[X];

		int count = 0;
		set<int>::iterator itlow, itup;
		itlow = index_list.lower_bound (L);              //       ^
		itup = index_list.upper_bound (R);               //                   ^

		for (set<int>::iterator it = itlow; it != itup; ++it) {
			count ++;
		}

		cout << count << endl;
	}
}

