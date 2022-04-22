#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc241/tasks/abc241_b
*/


int main() {
	int N, M;
	vector<int> A;
	vector<bool> A_visited;
	vector<int> B;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
		A_visited.push_back(false);
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		B.push_back(temp);
	}

	for (int m = 0; m < M; m++) {
		int b = B[m];
		bool matched = false;
		for (int n = 0; n < N; n++) {
			int a = A[n];
			int visited = A_visited[n];
			if (visited) {
				continue;
			}

			if (b == a) {
				A_visited[n] = true;
				matched = true;
				break;
			}
		}

		if (!matched) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}


