#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/*
https://atcoder.jp/contests/abc235/tasks/abc235_c
*/

int main() {
	int N, Q;
	int a[200000];

	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	map<int, map<int, int> > counter;
	for (int i = 0; i < N; i++) {
		int a_i = a[i];
//		cout << "a_i" << a_i << endl;

		if (counter.count(a_i) == 0) {
//			cout << "create inner map" << endl;
			map<int, int> times;
			counter[a_i] = times;
		}

		map<int, int> &times = counter[a_i];
		int size = times.size();
//		cout << "size=" << size << endl;
		times[size] = i;
//		cout << "times[size]=" << times[size] << endl;
	}

	for (int i = 0; i < Q; i++) {
		int x, k;
		cin >> x >> k;

		if (counter.count(x) == 0) {
			cout << "-1" << endl;
		} else {
			if (counter[x].count(k - 1) == 0) {
				cout << "-1" << endl;
			} else {
				cout << counter[x][k - 1] + 1 << endl;
			}
		}
	}
}