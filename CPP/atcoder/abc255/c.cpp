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

	x += 1e18;
	a += 1e18;

	long long min = 0;
	long long max = 2e18;

	if (d == 0) {
		cout << abs(x - a) << endl;
	} else if (d > 0) {
		long long max_times = (max - a) / d;
		long long end = -1;
		if (max_times >= n) {
			end = a + n * d;
		} else {
			end = a + max_times * d;
		}

		if (x <= a) {
			cout << a - x << endl;
		} else if (x >= end) {
			cout << x - end << endl;
		} else {
			long long inc = x - a;
			long long quotient = inc % d;

			if (quotient <= d / 2) {
				cout << quotient << endl;
			} else {
				cout << d - quotient << endl;
			}
		}
	} else if (d < 0) {
		long long max_times = abs(min - a) / abs(d);
		long long end = -1;
		if (max_times >= n) {
			end = a + n * d;
		} else {
			end = a + max_times * d;
		}

		if (x >= a) {
			cout << x - a << endl;
		} else if (x <= end) {
			cout << end - x << endl;
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
