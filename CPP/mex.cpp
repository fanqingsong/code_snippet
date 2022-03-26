#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://atcoder.jp/contests/abc245/tasks/abc245_b
*/

int main() {
	int N;
	vector<int> A;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}

	// https://www.tutorialspoint.com/sorting-a-vector-in-cplusplus
	sort(A.begin(), A.end());

	if (A[0] > 0) {
		cout << 0 << endl;
	} else {
		for (long unsigned int i = 0; i < A.size() - 1; i++) {
			int next_expect = 0;
			next_expect = A[i] + 1;

			if (A[i + 1] == A[i] || A[i + 1] == next_expect) {
				continue;
			} else {
				cout << next_expect << endl;
				return 0;
			}
		}

		cout << A[A.size() - 1] + 1 << endl;
	}
}