#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;


/*
https://atcoder.jp/contests/abc246/tasks/abc246_a
*/

int main() {
	double A, B;

	double x, y;

	cin >> A >> B;

	y = sqrt(B * B / (A * A + B * B));
	x = sqrt(A * A / (A * A + B * B));

	cout << x << " " << y << endl;

	return 0;
}