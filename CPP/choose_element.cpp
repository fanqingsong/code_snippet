#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://atcoder.jp/contests/abc245/tasks/abc245_b
*/

bool in_k_limit(vector<int> &A, vector<int> &B, long unsigned int index, int prev_val, int K) {
	if (index > A.size() - 1) {
		return false;
	}

	int a_v = A[index];
	int b_v = B[index];

	int a_diff = abs(a_v - prev_val);
	int b_diff = abs(b_v - prev_val);

//	cout << index << " " << a_diff << " " << b_diff << endl;

	if (a_diff <= K) {
		if (index == A.size() - 1) {
			return true;
		} else if (in_k_limit(A, B, index + 1, a_v, K)) {
			return true;
		}
	}

	if (b_diff <= K) {
		if (index == A.size() - 1) {
			return true;
		} else if (in_k_limit(A, B, index + 1, b_v, K)) {
			return true;
		}
	}

	return false;
}

int main() {
	int N, K;
	vector<int> A, B;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		B.push_back(temp);
	}

	if (in_k_limit(A, B, 1, A[0], K)) {
		cout << "Yes" << endl;
	} else if (in_k_limit(A, B, 1, B[0], K)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}