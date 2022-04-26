#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc209/tasks/abc209_b
*/


int main() {
	int n, x;
	int sum = 0;

	cin >> n >> x;

	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;

		int cost = temp;
		if (i % 2 == 0) {
			cost --;
		}

		sum += cost;
	}

	if (sum <= x) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}


