#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <set>

/*
https://atcoder.jp/contests/abc255/tasks/abc255_c
*/

int main() {
	long long x, a, d, n;

	cin >> x >> a >> d >> n;

	long long min = -1e18;
	long long max = 1e18;

	if (d == 0) {
		cout << abs(x - a) << endl;
	} else if (d > 0) {
		long long max_times = abs(max - a) / d;
//		cout << "max times = " << max_times << endl;
		long long end = a;
//		cout << n << endl;
		if (max_times >= n - 1) {
//			cout << "great condition" << endl;
			end = a + (n - 1) * d;
		} else {
//			cout << "less condition" << endl;
			end = a + max_times * d;
		}
//		cout << "end = " << end << endl;

		if (x <= a) {
			cout << abs(a - x) << endl;
		} else if (x >= end) {
			cout << abs(x - end) << endl;
		} else {
			long long inc = abs(x - a);
			long long quotient = inc % d;

			if (quotient <= d / 2) {
				cout << quotient << endl;
			} else {
				cout << d - quotient << endl;
			}
		}
	} else if (d < 0) {
		long long max_times = abs(min - a) / abs(d);
		long long end = a;
		if (max_times >= n - 1) {
			end = a + (n - 1) * d;
		} else {
			end = a + max_times * d;
		}

		if (x >= a) {
			cout << abs(x - a) << endl;
		} else if (x <= end) {
			cout << abs(end - x) << endl;
		} else {
			long long inc = abs(x - a);
			long long quotient = inc % abs(d);

			if (quotient <= abs(d) / 2) {
				cout << quotient << endl;
			} else {
				cout << abs(d) - quotient << endl;
			}
		}
	}

	return 0;
}
