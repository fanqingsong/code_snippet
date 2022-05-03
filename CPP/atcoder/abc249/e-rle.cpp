#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/abc249/tasks/abc249_e
*/

#define N_LIMIT 3010

int f[N_LIMIT][N_LIMIT * 2] = {{0}};

//int pref[N_LIMIT][N_LIMIT * 2] = {{0}};

int get(int k) {
	if (k >= 1 && k < 10) {
		return 2;
	} else if (k >= 10 && k < 100) {
		return 3;
	} else if (k >= 100 && k < 1000) {
		return 4;
	} else if (k >= 1000 && k < 10000) {
		return 5;
	}
}

int got(int x) {
	if (x == 2)
		return 9;
	if (x == 3)
		return 99;
	if (x == 4)
		return 999;
	if (x == 5)
		return 9999;
}

int main() {
	int n, p;

	cin >> n >> p;

	for (int i = 1; i <= n; i++) {
		f[i][get(i)] = 26;
//		pref[i][get(i)] = pref[i - 1][get(i)] + f[i][get(i)];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * i; j++) { // worst situation
			for (int k = 1; k <= i && get(k) <= j; k++) {
				f[i][j] += f[i - k][j - get(k)] * 25;
				f[i][j] %= p;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i < n; i++ ) {
		sum += f[n][i];
		sum %= p;
	}

	cout << sum << endl;
}