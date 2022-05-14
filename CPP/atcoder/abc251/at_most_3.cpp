#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;



/*
https://atcoder.jp/contests/abc251/tasks/abc251_b
*/

int main() {
	int n, w;

	int a[312] = {0};
	set<int> all_values;

	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		if (a[i] <= w) {
			all_values.insert(a[i]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = a[i] + a[j];
			if (sum <= w) {
				all_values.insert(sum);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = a[i] + a[j] + a[k];
				if (sum <= w) {
					all_values.insert(sum);
				}
			}
		}
	}

	cout << all_values.size() << endl;
}
