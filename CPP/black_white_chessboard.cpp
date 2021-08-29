#include <iostream>
#include <cmath>

using namespace std;

bool is_BW(char *chessrow) {
	int len = strlen(chessrow);
	char one_char = 0;
	for (int i = 0; i < len; i++) {
		one_char = chessrow[i];
		if (one_char != 'W' && one_char != 'B') {
			return false;
		}
	}

	return true;
}

int scan_row_black(char chessboard[8][32]) {
	int count = 0;
	bool is_all_black;
	char one_char;

	for (int i = 0; i < 8; i++) {
		is_all_black = true;
		for (int j = 0; j < 8; j++) {
			one_char = chessboard[i][j];
			if ('W' == one_char) {
				is_all_black = false;
				break;
			}
		}

		if (is_all_black) {
			count++;
		}
	}

	return count;
}

int scan_col_black(char chessboard[8][32]) {
	int count = 0;
	bool is_all_black;
	char one_char;

	for (int i = 0; i < 8; i++) {
		is_all_black = true;
		for (int j = 0; j < 8; j++) {
			one_char = chessboard[j][i];
			if ('W' == one_char) {
				is_all_black = false;
				break;
			}
		}

		if (is_all_black) {
			count++;
		}
	}

	return count;
}

int main() {
	char chessboard[8][32] = {0};
	int count_row = 0;
	int count_col = 0;
	int count_all = 0;

	for (int i = 0; i < 8; i++) {
		cin >> chessboard[i];

		cout << chessboard[i] << endl;

		while (strlen(chessboard[i]) != 8) {
			cout << "every row of chess board only has 8 cell. please input again." << endl;
			cin >> chessboard[i];
		}

		while (!is_BW(chessboard[i])) {
			cout << "only B W can be inputed. please input again." << endl;
			cin >> chessboard[i];
		}
	}

	count_row = scan_row_black(chessboard);
	count_col = scan_col_black(chessboard);

	count_all = count_row + count_col;

	cout << count_all << endl;
}

