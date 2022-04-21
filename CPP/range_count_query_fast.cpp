#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <deque>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc248/tasks/abc248_d
*/

int main() {
	int N;
	map<int, vector<int>> gp;

	int Q;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		gp[temp].push_back(i);
	}

	cin >> Q;

	for (int i = 0; i < Q; i++) {
		int L, R, X;
		cin >> L >> R >> X;

		vector<int> &index_list = gp[X];

		int low_index = -1;
		int up_index = -1;
		int size = index_list.size();

		int low = 0;
		int up = size - 1;
		int middle = 0;
		int mid_value = 0;
		while (low <= up) {
			middle = (low + up) / 2;
			mid_value = index_list[middle];
			if (mid_value == L) {
				low_index = middle;
				break;
			} else if (mid_value < L) {
				low = middle + 1;
			} else if (mid_value > L) {
				up = middle - 1;
			}
		}

		if (low_index == -1) {
			// up = low - 1
			// means: index_list[up] < L < index_list[low]
			low_index = low;
		}

		low = 0;
		up = size - 1;
		middle = 0;
		while (low <= up) {
			middle = (low + up) / 2;
			mid_value = index_list[middle];
			if (mid_value == R) {
				up_index = middle;
				break;
			} else if (mid_value < R) {
				low = middle + 1;
			} else if (mid_value > R) {
				up = middle - 1;
			}
		}

		if (up_index == -1) {
			// up = low - 1
			// means: index_list[up] < R < index_list[low]
			up_index = up;
		}

		int count = 0;
		count = up_index - (low_index - 1);

		cout << count << endl;
	}
}

