#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

int N;
int hi[100005];


int dfs(int n) {
	if (n <= 1) {
		return 1;
	}

	if ( n == 2 ) {
		if (hi[1] != hi[2]) {
			return 2;
		} else {
			return 1;
		}
	}

	int diff_n1 = hi[n - 1] - hi[n - 2];
	int diff_n = hi[n] - hi[n - 1];
	if ((diff_n1 < 0 && diff_n < 0)
	        || (diff_n1 > 0 && diff_n > 0)
	        || diff_n == 0 ) {
		return dfs(n - 1);
	} else {
		return dfs(n - 1) + 1;
	}
}

int main() {
	cin >> N;

	for (int n = 1; n <= N; n++) {
		cin >> hi[n];
	}

	int count = dfs(N);

	cout << count << endl;
}
