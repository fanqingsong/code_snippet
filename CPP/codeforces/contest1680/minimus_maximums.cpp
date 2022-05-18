#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
https://codeforces.com/problemset/problem/1680/A
*/

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int l1, r1, l2, r2;

		cin >> l1 >> r1 >> l2 >> r2;

		bool overlaped = false;
		int minimum = 0;


		for (int j = 1; j <= 50; j++) {
			if (j >= l1 && j <= r1) {
				if (j >= l2 && j <= r2) {
					overlaped = true;
					minimum = j;
					break;
				}
			}
		}

		if (overlaped == true) {
			cout << minimum << endl;
		} else {
			cout << l1 + l2 << endl;
		}
	}
}
