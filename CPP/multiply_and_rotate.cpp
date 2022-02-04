
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*
https://atcoder.jp/contests/abc235/tasks/abc235_d
*/


int main() {
	int a, N;

	cin >> a >> N;

	long long max = 1000000;
	vector<int> d(max, -1);
	d[1] = 0;

	queue<int> Q;
	Q.push(1);

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		long long next = x * a;
		if ( next < max ) {
			if (d[next] == -1) {
				Q.push(next);
				d[next] = d[x] + 1;
			}
		}

		if (x >= 10 && x % 10 != 0) {
			string S = to_string(x);
			rotate(S.begin(), S.end() - 1, S.end());
			int next = stoi(S);

			if (d[next] == -1) {
				Q.push(next);
				d[next] = d[x] + 1;
			}
		}
	}

	cout << d[N] << endl;
}
