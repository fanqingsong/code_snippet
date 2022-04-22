#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc241/tasks/abc241_c
*/


int main() {
	int N;
	bool S[1000][1000] = {{false}};

	cin >> N;

	for (int i = 0; i < N; i++) {
		string s_line;
		cin >> s_line;

		int size = s_line.size();
		for (int j = 0; j < size; j++) {
			char square = s_line[j];
			if ('#' == square ) {
				S[i][j] = true;
			} else if ('.' == square) {
				S[i][j] = false;
			}
		}
	}

	// search row
	for (int i = 0; i < N; i++) {
		int count = 0;

		// count first six squares
		int index = 0;
		while (index++ <= 5) {
			if (S[i][index] == true) {
				count++;
			}
		}

		if (count >= 4) {
			cout << "Yes" << endl;
			return 0;
		}

		int low = 0;
		int up = 5;

		while (true) {
			// move to right one square
			low ++;
			up ++;
			if (up >= N) {
				break;
			}

			if (S[i][low - 1] == true) {
				count --;
			}

			if (S[i][up] == true) {
				count ++;
			}

			if (count >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	// search colomn
	for (int i = 0; i < N; i++) {
		int count = 0;

		// count first six squares
		int index = 0;
		while (index++ <= 5) {
			if (S[index][i] == true) {
				count++;
			}
		}

		if (count >= 4) {
			cout << "Yes" << endl;
			return 0;
		}

		int low = 0;
		int up = 5;

		while (true) {
			// move to bottom one square
			low ++;
			up ++;
			if (up >= N) {
				break;
			}

			if (S[low - 1][i] == true) {
				count --;
			}

			if (S[up][i] == true) {
				count ++;
			}

			if (count >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	// search diagonally - backslash(\) - upper
	for (int j = 0; j <= N - 6; j++ ) {
		int count = 0;

		// count first six squares
		int i = 0;
		while (i++ <= 5) {
			if (S[i][i + j] == true) {
				count++;
			}
		}

		if (count >= 4) {
			cout << "Yes" << endl;
			return 0;
		}

		int low_i = 0;
		int up_i = 5;
		while (true) {
			low_i ++;
			up_i ++;

			if (up_i > N - 6) {
				break;
			}

			if (S[low_i - 1][low_i - 1 + j] == true) {
				count --;
			}

			if (S[up_i][up_i + j] == true) {
				count ++;
			}

			if (count >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	// search diagonally - backslash(\) - lower
	for (int i = 0; i <= N - 6; i++ ) {
		int count = 0;

		// count first six squares
		int j = 0;
		while (j++ <= 5) {
			if (S[i + j][j] == true) {
				count++;
			}
		}

		if (count >= 4) {
			cout << "Yes" << endl;
			return 0;
		}

		int low_j = 0;
		int up_j = 5;
		while (true) {
			low_j ++;
			up_j ++;

			if (up_j > N - 6) {
				break;
			}

			if (S[i + low_j - 1][low_j - 1] == true) {
				count --;
			}

			if (S[i + up_j][up_j] == true) {
				count ++;
			}

			if (count >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	// search diagonally - slash(/) - upper
	for (int j = 5; j <= N - 1; j++ ) {
		int count = 0;

		// count first six squares
		int i = 0;
		while (i++ <= 5) {
			if (S[i][5 - i] == true) {
				count++;
			}
		}

		if (count >= 4) {
			cout << "Yes" << endl;
			return 0;
		}

		int low_i = 0;
		int up_i = 5;
		while (true) {
			low_i ++;
			up_i ++;

			if (up_i > N - 1) {
				break;
			}

			if (S[low_i - 1][j - (low_i - 1)] == true) {
				count --;
			}

			if (S[up_i][j - up_i] == true) {
				count ++;
			}

			if (count >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	// search diagonally - slash(/) - lower
	for (int i = 0; i <= N - 6; i++ ) {
		int count = 0;

		// count first six squares
		int j = 0;
		while (j++ <= 5) {
			if (S[j + i][N - 1 + i - j] == true) {
				count++;
			}
		}

		if (count >= 4) {
			cout << "Yes" << endl;
			return 0;
		}

		int low_j = 0;
		int up_j = 5;
		while (true) {
			low_j ++;
			up_j ++;

			if (up_j > N - 6) {
				break;
			}

			if (S[j + (low_j - 1)][N - 1 + i - (low_j - 1)] == true) {
				count --;
			}

			if (S[j + up_j][N - 1 + i - up_j] == true) {
				count ++;
			}

			if (count >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;

	return 0;
}


