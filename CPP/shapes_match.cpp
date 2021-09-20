#include <iostream>

using namespace std;

//https://atcoder.jp/contests/abc218/tasks/abc218_c

bool get_shape_data(int shape[200][200], int dimension) {
	char one_char;

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			cin >> one_char;
			if ('#' == one_char) {
				shape[i][j] = 1;
			} else if ('.' == one_char) {
				shape[i][j] = 0;
			} else {
				return false;
			}
		}
	}

	return true;
}

bool is_shape_matched(int shape_a[200][200], int shape_b[200][200], int dimension) {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			if (shape_a[i][j] != shape_b[i][j]) {
				return false;
			}
		}
	}

	return true;
}

// rotate shape clockwise by 90-degree
bool rotate_shape(int shape_in[200][200], int shape_out[200][200], int dimension) {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			shape_out[j][dimension - i - 1] = shape_in[i][j];
		}
	}

	return true;
}

bool copy_shape(int shape_in[200][200], int shape_out[200][200], int dimension) {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			shape_out[i][j] = shape_in[i][j];
		}
	}

	return true;
}

bool rotate_shape_selfly(int shape[200][200], int dimension) {
	int shape_rotated[200][200] = {0};
	int ret = false;

	cout << "before rotate." << endl;
	ret = rotate_shape(shape, shape_rotated, dimension);
	if (!ret) {
		cout << "rotate shape got failed." << endl;
		return false;
	}

	cout << "before copy." << endl;
	ret = copy_shape(shape_rotated, shape, dimension);
	if (!ret) {
		cout << "copy shape got failed." << endl;
		return false;
	}

	return true;
}


int get_first_valid_row(int shape[200][200], int dimension) {
	bool is_all_zero = true;

	for (int i = 0; i < dimension; i++) {
		is_all_zero = true;

		for (int j = 0; j < dimension; j++) {
			if (shape[i][j] != 0) {
				is_all_zero = false;
				break;
			}
		}

		if (!is_all_zero) {
			return i;
		}
	}

	return -1;
}

int get_first_valid_col(int shape[200][200], int dimension) {
	bool is_all_zero = true;

	for (int j = 0; j < dimension; j++) {
		is_all_zero = true;

		for (int i = 0; i < dimension; i++) {
			if (shape[i][j] != 0) {
				is_all_zero = false;
				break;
			}
		}

		if (!is_all_zero) {
			return j;
		}
	}

	return -1;
}

// transalte shape to left - top corner
bool translate_shape(int shape_in[200][200], int shape_out[200][200], int dimension) {
	int first_valid_row = -1;
	int first_valid_col = -1;

	first_valid_row = get_first_valid_row(shape_in, dimension);

	first_valid_col = get_first_valid_col(shape_in, dimension);

	for (int i = first_valid_row; i < dimension; i++) {
		for (int j = first_valid_col; j < dimension; j++) {
			shape_out[i - first_valid_row][j - first_valid_col] = shape_in[i][j];
		}
	}

	return true;
}

bool compare_shape_normally(int shape_a[200][200], int shape_b[200][200], int dimension) {
	int shape_a_std[200][200] = {0};
	int shape_b_std[200][200] = {0};
	int ret = false;

	ret = translate_shape(shape_a, shape_a_std, dimension);
	if (!ret) {
		cout << "translate shape a got failed." << endl;
		return false;
	}

	ret = translate_shape(shape_b, shape_b_std, dimension);
	if (!ret) {
		cout << "translate shape b got failed." << endl;
		return false;
	}

	if (is_shape_matched(shape_a_std, shape_b_std, dimension)) {
		cout << "shape a matched shape b." << endl;
		return true;
	}

	return false;
}

void print_shape(int shape[200][200], int dimension) {
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			cout << shape[i][j];
		}
		cout << endl;
	}
}

int main() {
	int shape_a[200][200] = {0};
	int shape_b[200][200] = {0};

	int dimension = 0;
	bool ret = false;

	cin >> dimension;

	ret = get_shape_data(shape_a, dimension);
	if (!ret) {
		cout << "shape a got failed." << endl;
		return 0;
	}

	print_shape(shape_a, dimension);

	ret = get_shape_data(shape_b, dimension);
	if (!ret) {
		cout << "shape b got failed." << endl;
		return 0;
	}

	print_shape(shape_b, dimension);

	cout << "-------------------------------" << endl;
	if (compare_shape_normally(shape_a, shape_b, dimension)) {
		cout << "shape a matched shape b." << endl;
		return 0;
	}

	cout << "-------------------------------" << endl;
	ret = rotate_shape_selfly(shape_a, dimension);
	if (!ret) {
		cout << "rotate shape a got failed." << endl;
		return 0;
	}

	print_shape(shape_a, dimension);

	if (compare_shape_normally(shape_a, shape_b, dimension)) {
		cout << "shape a matched shape b." << endl;
		return 0;
	}

	cout << "-------------------------------" << endl;
	ret = rotate_shape_selfly(shape_a, dimension);
	if (!ret) {
		cout << "rotate shape a got failed." << endl;
		return 0;
	}
	print_shape(shape_a, dimension);

	if (compare_shape_normally(shape_a, shape_b, dimension)) {
		cout << "shape a matched shape b." << endl;
		return 0;
	}

	cout << "-------------------------------" << endl;
	ret = rotate_shape_selfly(shape_a, dimension);
	if (!ret) {
		cout << "rotate shape a got failed." << endl;
		return 0;
	}
	print_shape(shape_a, dimension);

	if (compare_shape_normally(shape_a, shape_b, dimension)) {
		cout << "shape a matched shape b." << endl;
		return 0;
	}
}



