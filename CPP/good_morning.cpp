#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://atcoder.jp/contests/abc245/tasks/abc245_a
*/

int main() {
	int A, B, C, D;

	cin >> A >> B >> C >> D;

	int tak_time = 0;
	int aok_time = 0;

	tak_time = A * 60 * 60 + B * 60;
	aok_time = C * 60 * 60 + D * 60 + 1;

	if (tak_time < aok_time) {
		cout << "Takahashi" << endl;
	} else {
		cout << "Aoki" << endl;
	}
}