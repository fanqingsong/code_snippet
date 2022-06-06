#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
https://atcoder.jp/contests/abc254/tasks/abc254_c
*/


vector<int> a(200004, 0);

map<int, vector<int>> groups;


int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		/*
		group indexed from 0 to k-1
		1  --> group 0
		2 --> group 1
		...
		k --> group k-1
		k+1 --> group 0
		k+2 --> group 1
		...
		*/
		int group_index = (i - 1) % k;
		groups[group_index].push_back(a[i]);
	}

	for (int i = 0; i < k; i++) {
		vector<int> &one_group = groups[i];
		sort(one_group.begin(), one_group.end());
//
//		for (int j = 0; j < one_group.size(); j++) {
//			cout << one_group[j] << " " ;
//		}
//
//		cout << endl;
	}

	int prev = groups[0][0];
	for (int i = 2; i <= n; i++) {
		int group_num = (i - 1) % k;
		int column = (i - 1) / k;

		int now = groups[group_num][column];
		if (prev <= now) {
			prev = now;
			continue;
		} else {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}


