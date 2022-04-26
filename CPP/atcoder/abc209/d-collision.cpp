#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc209/tasks/abc209_d
*/

const int modulo = (1e9 + 7);

int main() {
	int n;
	vector<int> c;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		c.push_back(temp);
	}

	sort(c.begin(), c.end());

//	for (int i = 0; i < n; i++) {
//		cout << c[i] << endl;
//	}

	long long count = 1;

	for (int i = 0; i < n; i++) {
		int c_i = c[i];
		count *= c_i - i;
		count %= modulo;
	}

	cout << count << endl;

	return 0;
}


