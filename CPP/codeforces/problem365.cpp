#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/problemset/problem/365/b
*/

int main() {
	int n;

	cin >> n;

	int good_len = 0;
	if (n <= 2) {
		good_len = n;

		// discard input
		int temp;
		if (n == 1 || n == 2) {
			cin >> temp;
		}
		if (n == 2) {
			cin >> temp;
		}

		cout << good_len << endl;

		return 0;
	}

	int a_i2 = 0;
	int a_i1 = 0;
	int a_i0 = 0;

	cin >> a_i2;
	cin >> a_i1;

	good_len = 2;

	int max_good_len = good_len;
	for (int i = 2; i < n; i++) {
//		cout << "i = " << i << endl;
		cin >> a_i0;
		if (a_i0 == a_i1 + a_i2) {
//			cout << "good len ++" << endl;
			good_len++;
//			cout << "good len=" << good_len << endl;
		}

		if (a_i0 != a_i1 + a_i2 || i == n - 1) {
//			cout << "good segment found" << endl;
			max_good_len = max(max_good_len, good_len);
			good_len = 2;
//			cout << "max_good_len=" << max_good_len << endl;
		}

		a_i2 = a_i1;
		a_i1 = a_i0;
	}

	cout << max_good_len << endl;
}