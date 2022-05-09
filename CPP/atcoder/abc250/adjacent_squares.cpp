#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc250/tasks/abc250_a
*/

int main() {
	int h, w;
	int r, c;

	cin >> h >> w;
	cin >> r >> c;

	int count = 0;

	// right
	if (c + 1 <= w) {
		count++;
	}

	// down
	if (r + 1 <= h) {
		count++;
	}

	// left
	if (c - 1 >= 1) {
		count++;
	}

	// up
	if (r - 1 >= 1) {
		count++;
	}

	cout << count << endl;
}