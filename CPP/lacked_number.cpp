#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/abc248/tasks/abc248_a
*/

int main() {
	string S;
	cin >> S;

	bool vis[32] = {false};

	for (auto x : S) {
		int index = x - '0';
		if (vis[index] == false) {
			vis[index] = true;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (vis[i] == false) {
			cout << i << endl;
			break;
		}
	}
}

