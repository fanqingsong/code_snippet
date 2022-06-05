#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
https://atcoder.jp/contests/abc254/tasks/abc254_d
*/

int bi_factor_num(int n) {
	int count = 0;

	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			count ++;
		}
	}

	return count;
}

int dp(int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		count += bi_factor_num(i) * 2;
	}

	count += n;

	return count;
}

int main() {
	int n;

	cin >> n;

	int ans = dp(n);

	cout << ans << endl;
}
