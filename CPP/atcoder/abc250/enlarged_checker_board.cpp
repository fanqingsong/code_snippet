#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc250/tasks/abc250_b
*/

int main() {
	int n, a, b;

	cin >> n >> a >> b;

	// big rows
	for (int r = 0; r < n; r++) {

		// nested rows
		for (int ai = 0; ai < a; ai++) {
			string temp_row = "";

			// big colomns
			for (int c = 0; c < n; c++) {
				bool white_flag = false;
				if ((r + c) % 2 == 0) {
					white_flag = true;
				} else {
					white_flag = false;
				}

				// nested colomns
				string temp_col;
				for (int bi = 0; bi < b; bi++) {
					if (white_flag) {
						temp_col += ".";
					} else {
						temp_col += "#";
					}
				}

				temp_row += temp_col;
			}

			cout << temp_row << endl;
		}
	}
}