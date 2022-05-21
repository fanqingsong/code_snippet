#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
https://atcoder.jp/contests/abc252/tasks/abc252_c
*/

int N;
int S[106][12];

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < 10; j++) {
			char one = temp[j];
			S[i][j + 1] = one - '0';
		}
	}

	// for every digit 0 -9
	int minimum = 1e9;
	for (int i = 0; i < 10; i++) {
		int counter[10] = {0};

		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= 10; k++) {
				if (i == S[j][k]) {
					counter[k - 1]++;
					break;
				}
			}
		}

		int max_value = -1;
		int max_index = -1;
		for (int j = 0; j < 10; j++) {
			if (max_value <= counter[j]) {
				max_value = counter[j];
				max_index = j;
			}
		}

//		if (i == 8) {
//			for (int h = 0; h < 10; h++) {
//				cout << counter[h] << " ";
//			}
//			cout << endl;
//
//			cout << "max_value = " << max_value << endl;
//			cout << "max_index = " << max_index << endl;
//		}

		int sum = 10 * (max_value - 1) + max_index;
		if (minimum > sum) {
			minimum = sum;
		}
	}

	cout << minimum << endl;
}
