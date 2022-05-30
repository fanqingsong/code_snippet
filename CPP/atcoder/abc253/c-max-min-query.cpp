#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>

/*
https://atcoder.jp/contests/abc253/tasks/abc253_c
*/

map<long long, bool> S;
map<long long, int> counter;


int main() {
	int Q;

	cin >> Q;

	for (int q = 0; q < Q; q++) {
		int action;
		long long x;
		int c;

		cin >> action;

		if (action == 1) {
			cin >> x;

			if (S[x] == false) {
				S[x] = true;
			}
			counter[x] ++;
		} else if (action == 2) {
			cin >> x;
			cin >> c;

			int times = min(c, counter[x]);
			counter[x] -= times;

			if (counter[x] == 0) {
				S.erase(x);
			}
		} else if (action == 3) {
//			// showing contents:
//			std::cout << "mymap contains:\n";
//			map<int, bool>::iterator it;
//			for (it = S.begin(); it != S.end(); ++it)
//				std::cout << it->first << " => " << it->second << '\n';

			long long min = S.begin()->first;
			long long max = S.rbegin()->first;
//			cout << "min = " << min << endl;
//			cout << "max = " << max << endl;
			cout << max - min << endl;
		}
	}

	return 0;
}
