#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;


/*
https://atcoder.jp/contests/abc246/tasks/abc246_c
*/

int main() {
	int N, K, X;

	cin >> N >> K >> X;
	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
	}

//	cout << "------------" << endl;
//	for (int i = 0; i < N; i++)
//		cout << A[i] << " ";
//	cout << endl;


	// delete the whole coupon value as many as possible
	int k_left = K;
	for (int i = 0; i < N; i++) {
		if (k_left <= 0) {
			break;
		}

		if (A[i] >= X) {
			int n_coupon = A[i] / X;
//			cout << "n_coupon=" << n_coupon << endl;
//			cout << "k_left=" << k_left << endl;
			if (n_coupon <= k_left) {
				A[i] = A[i] - n_coupon * X;
				k_left -= n_coupon;
			} else {
				A[i] = A[i] - k_left * X;
				k_left -= k_left;
			}
		}
	}

//	cout << "------------" << endl;
//	for (int i = 0; i < N; i++)
//		cout << A[i] << " ";
//	cout << endl;

	// sort A
	sort(A.begin(), A.end(), greater<int>());

	// delete the greater ones from left to right
	for (int i = 0; i < N; i ++) {
		if (k_left <= 0) {
			break;
		}

		A[i] = 0;
		k_left --;
	}

	// cout total
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i];
	}

	cout << sum << endl;

	return 0;
}