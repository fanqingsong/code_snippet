#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>

/*
https://atcoder.jp/contests/abc253/tasks/abc253_d
*/


long long gcd(long long m, long long n) {
	if (n == 0) {
		return m;
	}

	return gcd(n, m % n);
}

long long lcm(long long m, long long n) {
	return n / gcd(m, n) * m;
}

int main() {
	long long n, a, b;

	cin >> n;
	cin >> a >> b;

	/*
	https://www.cnblogs.com/sh0922/p/16313087.html
	*/

	long long times_a = n / a;
	long long times_b = n / b;
	long long lcm_ab = lcm(a, b);
	long long times_ab = n / lcm_ab;

	long long sum_a = (1 + times_a) * times_a / 2 * a;
	long long sum_b = (1 + times_b) * times_b / 2 * b;
	long long sum_ab = (1 + times_ab) * times_ab / 2 * lcm_ab;

	long long sum_union = sum_a + sum_b - sum_ab;

	long long sum = (1 + n) * n / 2;

	cout << sum - sum_union << endl;

	return 0;
}
