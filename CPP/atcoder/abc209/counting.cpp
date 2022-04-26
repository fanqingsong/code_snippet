#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc209/tasks/abc209_a
*/


int main() {
	int a, b;

	cin >> a >> b;

	if (a > b) {
		cout << 0 << endl;
	} else {
		cout << b - a + 1 << endl;
	}

	return 0;
}


