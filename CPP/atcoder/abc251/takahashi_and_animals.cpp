#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc251/tasks/abc251_e
*/

const int N = 300000 + 16;

int n;
int a[N] = {0};

long long dp[N][2] = {{0}};

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	/*
	dp[i][j] -- the cost to feed all top i cats
	but for i cat, it has two situations:
	dp[i][0] -- don't feed i cat with a[i] food cost
	dp[i][1] -- feed i cat with a[i] food cost

	generally speaking:
	dp[i][0] = dp[i-1][1]  // due to lack of feeding a[i] to i cat, then i-1 cat must be fed
	dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + a[i] // due to i cat fed with a[i], so i-1 cat can be fed or not

	but for i == 1, it depends on if n cat was fed with a[n] or not
	case 1
		if n cat was fed with a[n], then 1 cat can be fed or not
		dp[1][0] = 0
		dp[1][1] = a[1]
	case 2
		if n cat was not fed with a[n], then 1 cat should be fed only
		dp[1][0] = INF
		dp[1][1] = a[1]
	*/

	long long ans = 1e18;

	// for case 1
	dp[1][0] = 0;
	dp[1][1] = a[1];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
	}

	ans = min({ans, dp[n][1]});

	// for case 2
	dp[1][0] = 1e18;
	dp[1][1] = a[1];

	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
	}

	ans = min({ans, dp[n][0]});

	cout << ans << endl;
}