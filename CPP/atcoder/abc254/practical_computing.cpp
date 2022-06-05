#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
https://atcoder.jp/contests/abc254/tasks/abc254_b
*/

int a[32][32] = {{0}};

int main() {
	int n;

	cin >> n;

	a[0][0] = 1;

	cout << a[0][0] << endl;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				a[i][j] = a[i - 1][j];
			} else {
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}

			cout << a[i][j] << " ";
		}

		cout << endl;
	}
}
