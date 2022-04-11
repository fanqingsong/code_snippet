#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <deque>
#include <string>
using namespace std;


/*
https://atcoder.jp/contests/abc247/tasks/abc247_a
*/

int main() {
	string S;

	cin >> S;

	S.insert(0, "0");
	S.erase(S.size() - 1, 1);

	cout << S << endl;

	return 0;
}

