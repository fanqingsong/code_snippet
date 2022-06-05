#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
https://atcoder.jp/contests/abc254/tasks/abc254_a
*/

int main() {
	int n;

	cin >> n;

	int one = n % 10;

	int remainder = n / 10;

	int ten = remainder % 10;

	cout << ten << one << endl;
}
