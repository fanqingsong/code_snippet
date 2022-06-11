#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>

/*
https://atcoder.jp/contests/abc255/tasks/abc255_a
*/

// driver program to test above function
int main() {
	int r, c;

	int a[3][3];

	cin >> r >> c;

	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 2; j++) {
			cin >> a[i][j];
		}
	}

	cout << a[r][c] << endl;

	return 0;
}
