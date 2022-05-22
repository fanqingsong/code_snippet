#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
https://atcoder.jp/contests/abc252/tasks/abc252_d
*/

int N;
int A[200008];
map<int, int> mp;


int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		mp[A[i]] ++;
	}

	long long all_comb = (long long)(1) * N * (N - 1) / 2 * (N - 2) / 3;

	/*
	https://www.cnblogs.com/zengzk/p/16296821.html
	*/

	long long ans = all_comb;

	for (auto [_, c] : mp) {
		// delete 2 combination
		if (c >= 2) {
			long long two_comb = (long long)(1) * (N - c) * c * (c - 1) / 2;

			ans -= two_comb;

			// delete three combination
			if (c >= 3) {
				long long tri_comb = (long long)(1) * c * (c - 1) / 2 * (c - 2) / 3;

				ans -= tri_comb;
			}

		}


	}


	cout << ans << endl;
}
