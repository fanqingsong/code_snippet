#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

enum COLORS {
	RED,
	GREEN,
	BLUE,
};


int N, C;
COLORS mtx[100][100];
COLORS out[100][100];


int main() {
	cin >> N >> C;

	for (int n = 0; n < N; n++) {
		for (int c = 0; c < C; c++) {
			char temp;
			cin >> temp;

			if (temp == 'R') {
				mtx[n][c]	= RED;
			} else if (temp == 'G') {
				mtx[n][c] = GREEN;
			} else if (temp == 'B') {
				mtx[n][c] = BLUE;
			}
		}
	}

	for (int n = 0; n < N; n++) {
		for (int c = 0; c < C; c++) {
			int curr = mtx[n][c];

			int up = -1;
			int down = -1;
			int left = -1;
			int right = -1;

			if (n - 1 >= 0) {
				up = mtx[n - 1][c];
			}

			if (n + 1 <= N - 1) {
				down = mtx[n + 1][c];
			}

			if (c - 1 >= 0) {
				left = mtx[n][c - 1];
			}

			if (c + 1 <= N - 1) {
				right = mtx[n][c + 1];
			}

			if (curr == RED) {
				if (up == BLUE || down == BLUE || left == BLUE || right == BLUE) {
					out[n][c] = BLUE;
				} else {
					out[n][c] = RED;
				}
			}

			if (curr == GREEN) {
				if (up == RED || down == RED || left == RED || right == RED) {
					out[n][c] = RED;
				} else {
					out[n][c] = GREEN;
				}
			}

			if (curr == BLUE) {
				if (up == GREEN || down == GREEN || left == GREEN || right == GREEN) {
					out[n][c] = GREEN;
				} else {
					out[n][c] = BLUE;
				}
			}
		}
	}


	for (int n = 0; n < N; n++) {
		for (int c = 0; c < C; c++) {
			int curr = out[n][c];

			if (curr == RED) {
				cout << "R";
			} else if (curr == GREEN) {
				cout << "G";
			} else if (curr == BLUE) {
				cout << "B";
			}
		}

		cout << endl;
	}
}
