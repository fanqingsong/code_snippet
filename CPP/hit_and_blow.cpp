#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/abc243/tasks/abc243_b
*/

int main() {
	int n;
	int a[1000] = {0};
	int b[1000] = {0};
	bool aflag[1000] = {false};
	bool bflag[1000] = {false};

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int count1 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			count1++;
			aflag[i] = true;
			bflag[i] = true;
		}
	}

	int count2 = 0;
	for (int ai = 0; ai < n; ai++) {
		if (aflag[ai]) {
			continue;
		}

		for (int bi = 0; bi < n; bi++) {
			if (bflag[bi]) {
				continue;
			}

			if (a[ai] == b[bi]) {
				count2++;
				aflag[ai] = true;
				bflag[bi] = true;
			}
		}
	}

	cout << count1 << endl;
	cout << count2 << endl;
}





