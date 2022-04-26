#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1669/problem/B
*/

int main() {
	int t;

	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		map<int, int> counter;

		cin >> n;

		vector<int> a;
		for (int j = 0; j < n; j++) {
			int a_j;
			cin >> a_j;
			a.push_back(a_j);
		}

		bool found = false;
		for (int j = 0; j < n; j++) {
			int a_j = a[j];
			if (counter.find(a_j) != counter.end()) {
				counter[a_j] ++;
			} else {
				counter[a_j] = 1;
			}

			if (counter[a_j] >= 3) {
				cout << a_j << endl;
				found = true;
				break;
			}
		}

		if (!found) {
			cout << -1 << endl;
		}
	}
}