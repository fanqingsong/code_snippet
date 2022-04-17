#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/abc248/tasks/abc248_d
*/

int main() {
	int N;
	vector<int> A;

	int Q;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}

	cin >> Q;

	for (int i = 0; i < Q; i++) {
		int L, R, X;
		cin >> L >> R >> X;

//		vector<int> freq(N, 0);
		int count = 0;
		for (int i = L; i <= R; i++) {
			if (A[i - 1] == X) {
				count ++;
			}
		}

		cout << count << endl;
	}
}

