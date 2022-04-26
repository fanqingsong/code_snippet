#include <bits/stdc++.h>
using namespace std;

/*
https://codeforces.com/contest/1669/problem/C
*/

int main() {
	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		map<bool, int> even_counter;
		map<bool, int> odd_counter;

		cin >> n;
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;

			if (j % 2 == 0) {
				if (temp % 2 == 0) {
					even_counter[true] ++;
				} else {
					even_counter[false] ++;
				}
			} else {
				if (temp % 2 == 0) {
					odd_counter[true] ++;
				} else {
					odd_counter[false] ++;
				}
			}
		}

		if (even_counter.size() > 1 || odd_counter.size() > 1) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
}