#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/abc248/tasks/abc248_b
*/

int main() {
	long long A;
	long long B;
	long long K;

	cin >> A >> B >> K;

	long long base = A;
	long long count = 0;
	while (true) {
		if (base >= B) {
			break;
		}

		base = base * K;
		count ++;
	}

	cout << count << endl;
}

