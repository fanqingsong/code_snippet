#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <set>

/*
https://atcoder.jp/contests/abc255/tasks/abc255_d
*/

int n, q;

vector<int> a;

vector<long long> acc;

int get_upper_bound(int x) {
	if (x < a[0]) {
		return -1;
	}

	if (x > a[a.size() - 1]) {
		return a.size();
	}

	int lower = 0;
	int upper = a.size() - 1;

	while (lower < upper) {
		if (lower + 1 == upper) {
			break;
		}

		int middle = (lower + upper) / 2;

		if (x < a[middle]) {
			if (x > a[middle  - 1]) {
				return middle  - 1;
			}

			upper = middle  - 1;
		} else if (x > a[middle]) {
			if (x < a[middle + 1]) {
				return middle;
			}

			lower = middle + 1;
		} else {
			return middle;
		}
	}

//	cout << "lower = " << lower << endl;
//	cout << "upper = " << upper << endl;

	if (a[upper] == x) {
		return upper;
	} else if (a[lower] == x) {
		return lower;
	} else {
		return lower;
	}
}

long long get_diff_sum(int i, int j, int x) {
	if (i > j) {
		return 0;
	}

//	cout << "i = " << i << endl;
//	cout << "j = " << j << endl;

	long long sum = acc[j] - acc[i] + a[i];

	long long xsum = (long long)x * (j - i + 1);

//	cout << "sum = " << sum << endl;
//	cout << "xsum =" << xsum << endl;

	return abs(sum - xsum);
}

long long get_action_number(int x) {
	int upper_bound = get_upper_bound(x);
//	cout << "upper bound = " << upper_bound << endl;

	if (upper_bound == -1 || upper_bound == a.size()) {
		return get_diff_sum(0, a.size() - 1, x);
	}

	long long lower_diff_sum = get_diff_sum(0, upper_bound, x);
	long long upper_diff_sum = get_diff_sum(upper_bound + 1, a.size() - 1, x);

	return lower_diff_sum + upper_diff_sum;
}

int main() {
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		a.push_back(temp);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++) {
		int temp = a[i];

		if (i == 0) {
			acc.push_back((long long)temp);
		} else {
			long long prev = acc[i - 1];
			long long curr = prev + (long long)temp;

			acc.push_back(curr);
		}
	}
//
//	vector<int>::iterator it;
//	cout << "---- a -------" << endl;
//	for (it = a.begin(); it != a.end(); it++) {
//		cout << *it << endl;
//	}
//	cout << endl;
//	cout << "---- a -------" << endl;

	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;

		long long num = get_action_number(x);
		cout << num << endl;
	}

	return 0;
}
