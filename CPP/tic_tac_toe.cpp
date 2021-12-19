#include <bits/stdc++.h>
using namespace  std;

/*
https://codeforces.com/problemset/problem/3/C
*/

bool is_won(char grid[3][3], char mark);

int count_cell(char grid[3][3], char mark) {
	int count = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == mark) {
				count++;
			}
		}
	}

	return count;
}

bool is_legal(char grid[3][3]) {
	int count_x = count_cell(grid, 'X');
	int count_0 = count_cell(grid, '0');
	int diff = count_x - count_0;

	if (diff == 0) {
		if (is_won(grid, 'X')) {
			return false;
		}

		return true;
	}

	if (diff == 1) {
		if (is_won(grid, '0')) {
			return false;
		}

		return true;
	}

	return false;
}

bool is_next_x(char grid[3][3]) {
	int count_x = count_cell(grid, 'X');
	int count_0 = count_cell(grid, '0');

	if (count_x == count_0) {
		return true;
	}

	return false;
}

bool is_next_0(char grid[3][3]) {
	int count_x = count_cell(grid, 'X');
	int count_0 = count_cell(grid, '0');

	if (count_x > count_0) {
		return true;
	}

	return false;
}

bool is_won(char grid[3][3], char mark) {
	for (int i = 0; i < 3; i++) {
		if (grid[i][0] == mark
		        && grid[i][1] == mark
		        && grid[i][2] == mark) {
			return true;
		}
	}

	for (int j = 0; j < 3; j++) {
		if (grid[0][j] == mark
		        && grid[1][j] == mark
		        && grid[2][j] == mark) {
			return true;
		}
	}

	if (grid[0][0] == mark && grid[1][1] == mark && grid[2][2] == mark) {
		return true;
	}

	if (grid[0][2] == mark && grid[1][1] == mark && grid[2][0] == mark) {
		return true;
	}

	return false;
}

int count_cell_in_row(char grid[3][3], char mark, int x) {
	int count = 0;
	for (int i = 0; i < 3; i++) {
		if (grid[x][i] == mark) {
			count++;
		}
	}

	return count;
}

int count_cell_in_col(char grid[3][3], char mark, int y) {
	int count = 0;

	for (int i = 0; i < 3; i++) {
		if (grid[i][y] == mark) {
			count++;
		}
	}

	return count;
}

int count_cell_in_diagonal(char grid[3][3], char mark) {
	int count = 0;

	for (int i = 0; i < 3; i++) {
		if (grid[i][i] == mark) {
			count++;
		}
	}

	return count;
}

bool is_even_in_row(char grid[3][3], int x) {
	int count_x = count_cell_in_row(grid, 'X', x);
	int count_0 = count_cell_in_row(grid, '0', x);

	if (count_x == count_0) {
		return true;
	}

	return false;
}

bool is_even_in_col(char grid[3][3], int y) {
	int count_x = count_cell_in_col(grid, 'X', y);
	int count_0 = count_cell_in_col(grid, '0', y);

	if (count_x == count_0) {
		return true;
	}

	return false;
}

bool is_even_in_diagonal(char grid[3][3]) {
	int count_x = count_cell_in_diagonal(grid, 'X');
	int count_0 = count_cell_in_diagonal(grid, '0');

	if (count_x == count_0) {
		return true;
	}

	return false;
}

bool is_draw_old(char grid[3][3]) {
	int count_x = count_cell(grid, 'X');
	int count_0 = count_cell(grid, '0');

	if (!(count_x == 4 && count_0 == 4)) {
		return false;
	}

	int dot_x = 0;
	int dot_y = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == '.') {
				dot_x = i;
				dot_y = j;
			}
		}
	}

	if (dot_x == dot_y) {
		if (is_even_in_row(grid, dot_x)
		        && is_even_in_col(grid, dot_y)
		        && is_even_in_diagonal(grid)) {
			return true;
		}
	} else {
		if (is_even_in_row(grid, dot_x)
		        && is_even_in_col(grid, dot_y)) {
			return true;
		}
	}

	return false;
}

bool is_draw(char grid[3][3]) {
	int count_x = count_cell(grid, 'X');
	int count_0 = count_cell(grid, '0');

	if (count_x == 5 && count_0 == 4) {
		if (!is_won(grid, 'X') && !is_won(grid, '0')) {
			return true;
		}
	}

	return false;
}

int main() {
	char grid[3][3] = {{0}};

	cin >> grid[0];
	cin >> grid[1];
	cin >> grid[2];

	if (!is_legal(grid)) {
		cout << "illegal" << endl;
	} else if (is_won(grid, 'X')) {
		cout << "the first player won" << endl;
	} else if (is_won(grid, '0')) {
		cout << "the second player won" << endl;
	} else if (is_draw(grid)) {
		cout << "draw" << endl;
	} else if (is_next_x(grid)) {
		cout << "first" << endl;
	} else if (is_next_0(grid)) {
		cout << "second" << endl;
	} else {
		//
	}
}