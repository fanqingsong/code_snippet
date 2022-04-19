#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/abc248/tasks/abc248_c
*/

const int modulo = 998244353;

int main() {
	int N;
	int M;
	int K;

	cin >> N >> M >> K;

	int dp[55][2505] = {0};

	int max_n = N;
	int max_k = K;
	int max_m = M;

	// initially, for packing 0 items, with the gravity below 0, the case number is 1.
	dp[0][0] = 1;

	// dp[n][k] means packing n items, with the gravity below k, the case number is its value.

	for (int n = 1; n <= max_n; n++) {
		for (int k = 1; k <= max_k; k++) {
			for (int m = 1; m <= max_m; m++) {
				if (k - m >= 0) {
					dp[n][k] += dp[n - 1][k - m];
					dp[n][k] %= modulo;
				}
			}
		}
	}

	int ans = 0;
	for (int k = 1; k <= max_k; k++) {
		ans += dp[N][k];
		ans %= modulo;
	}

	cout << ans << endl;
}

