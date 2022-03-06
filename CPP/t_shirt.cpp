#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/abc242/tasks/abc242_a
*/

int main() {
	int a, b, c, x;

	cin >> a >> b >> c >> x;

//	cout << a << b << c << x << endl;

	double r = 0;

	if (x <= a) {
		r = 1.0;
	} else if (x <= b) {
		r = float(c) / (b - a);
	} else {
		r = 0;
	}

	cout << r << endl;
}




