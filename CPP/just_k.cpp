#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc249/tasks/abc249_c
*/

#define N_LIMIT 15

int main() {
	int n, k;
	int counter[N_LIMIT][26] = {{0}};

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;

		int size = (int) temp.size();
		for (int j = 0; j < size; j++) {
			char one = temp[j];
			int index = one - 'a';
			counter[i][index]++;
		}
	}

	// n number of strings can get 2^n chosen substrings
	int ans = 0;
	for (int i = 0; i < (1 << n) ; i++) {
		int num_alpha = 0;
		// for every combination, calculate the target alphabets number
		for (int j = 0; j < 26; j++) {
			int count = 0;
			for (int k = 1; k <= n; k++) {
				if (i >> (k - 1) & 1) {
					count += counter[k - 1][j];
				}
			}

			if (count == k) {
				num_alpha ++;
			}
		}

		ans = max(ans, num_alpha);
	}

	cout << ans << endl;

	return 0;
}


