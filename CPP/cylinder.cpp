#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <deque>
#include <queue>
#include <string>
using namespace std;


/*
https://atcoder.jp/contests/abc247/tasks/abc247_d
*/

struct NODE {
	long long x;
	long long count;
};

int main() {
	int Q;

	cin >> Q;

	queue<NODE> qq;

	for (int i = 0; i < Q; i++) {
		int type;
		cin >> type;

		if (1 == type) {
			long long x, count;
			cin >> x;
			cin >> count;

			struct NODE one;
			one.count = count;
			one.x = x;

			qq.push(one);
		} else if (2 == type) {
			long long sum = 0, count = 0;
			cin >> count;

			while (count > 0) {
				if (qq.empty()) {
					break;
				}

				struct NODE &one = qq.front();
				long long one_count = one.count;
				long long one_x = one.x;

				if (count < one_count) {
					one.count -= count;
					sum += one_x * count;
					count = 0;
				} else {
					sum += one_x * one_count;
					count -= one_count;
					qq.pop();
				}
			}

			cout << sum << endl;
		}
	}

	return 0;
}

