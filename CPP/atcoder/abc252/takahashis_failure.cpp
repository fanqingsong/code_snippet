#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
https://atcoder.jp/contests/abc252/tasks/abc252_b
*/

int n, k;
int a[105];
int b[105];

int main() {
	cin >> n >> k;

	int max = 0;
	map<int, vector<int>> mp;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		if (a[i] > max) {
			max = a[i];
		}

		mp[a[i]].push_back(i);
	}

	vector<int> max_index = mp[max];
	int size = max_index.size();
	for (int i = 0; i < k; i++) {
		cin >> b[i];

		for (int j = 0; j < size; j++) {
			if (b[i] == max_index[j]) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;

	return 0;
}
