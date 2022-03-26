#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://atcoder.jp/contests/abc143/tasks/abc143_d
*/

int main() {
	int N;
	vector<int> L;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		L.push_back(temp);
	}

	// https://www.tutorialspoint.com/sorting-a-vector-in-cplusplus
	sort(L.begin(), L.end());

//	for (const auto &i : L)
//		cout << i << ' ' << endl;


}