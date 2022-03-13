#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/abc243/tasks/abc243_a
*/

int main() {
	int v, a, b, c;

	cin >> v >> a >> b >> c;

	int sum = a + b + c;

	int remainder = v % sum;

//	cout << remainder << endl;
	if (remainder - a < 0) {
		cout << 'F' << endl;
	} else if (remainder - a - b < 0) {
		cout << 'M' << endl;
	} else {
		cout << 'T' << endl;
	}
}




