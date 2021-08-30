#include <iostream>
#include <cmath>

using namespace std;

bool is_self_sym(char oneChar) {
	char self_sym[] = {
		'A', 'H', 'I', 'M',
		'm', 'O', 'o', 'T',
		'U', 'V', 'v', 'W',
		'w', 'X', 'x', 'Y'
	};

	for (int i = 0; i < strlen(self_sym); i++) {
		if (oneChar == self_sym[i]) {
			return true;
		}
	}

	return false;
}

bool is_shape_sym(char left, char right) {
	char shape_sym[2][4] = {
		{'d', 'b', 'p', 'q'},
		{'b', 'd', 'q', 'p'}
	};

	for (int i = 0; i < 4; i++ ) {
		if (left == shape_sym[0][i] && right == shape_sym[1][i]) {
			return true;
		}
	}

	return false;
}

bool is_mirror_sym(char left, char right) {
	if (is_self_sym(left) && is_self_sym(right)) {
		if (left == right) {
			return true;
		}
	}

	if (is_shape_sym(left, right)) {
		return true;
	}

	return false;
}

bool is_sym_str(char str[1024]) {
	int len = strlen(str);

	int middle = len / 2;

	if (len % 2 != 0) {
		char midChar = str[middle];
		if (!is_self_sym(midChar)) {
			return false;
		}
	}

	for (int i = 0; i < middle; i++) {
		char left = str[i];
		char right = str[len - 1 - i];

		if (!is_mirror_sym(left, right)) {
			return false;
		}
	}

	return true;
}

int main() {
	char multi_str[1000][1024] = {0};
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> multi_str[i];

		while (strlen(multi_str[i]) > 1000) {
			cout << "every string len must be less than 1000. please input again." << endl;
			cin >> multi_str[i];
		}
	}

	for (int i = 0; i < T; i++) {
		if (is_sym_str(multi_str[i])) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

