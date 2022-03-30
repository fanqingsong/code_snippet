#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://atcoder.jp/contests/abc245/tasks/abc245_d
*/

int get_b_coefficient(vector<int> &A, vector<int> &B, vector<int> &C, long unsigned int index) {
	int c_index = C[index];
	int b_acc = 0;

//	cout << "----------------" << index << endl;

	for (long unsigned int i = 0; i < index; i++) {
//		cout << "B[i] i=" << i << " " << B[i] << endl;
//		cout << "A[index - i] index-i=" << index - i << " " << A[index - i] << endl;

		if (index - i > A.size() - 1) {
			continue;
		}

		b_acc += B[i] * A[index - i];

//		cout << "b_acc = " << b_acc << endl;
	}

	int remaining = c_index - b_acc;
//	cout << "c_index = " << c_index << endl;
//	cout << "remaining = " << remaining << endl;

	int b_index = remaining / A[0];

	return b_index;
}

int main() {
	long unsigned int N, M;

	cin >> N >> M;
	vector<int> A(N + 1), B(M + 1), C(N + M + 1);

	for (long unsigned int i = 0; i <= N; i++) {
		cin >> A.at(i);
	}

	for (long unsigned int i = 0; i <= N + M; i++) {
		cin >> C.at(i);
	}

	for (long unsigned int i = 0; i <= M; i++) {
		B[i] = get_b_coefficient(A, B, C, i);
	}

	for (long unsigned int i = 0; i <= M; i++) {
		cout << B[i] << " ";
	}
}