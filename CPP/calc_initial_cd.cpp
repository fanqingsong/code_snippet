#include <iostream>
#include <cmath>

using namespace std;

bool test_x(int x, int sum) {
	if (sum % x != 0) {
		return false;
	}

	for (int day = 2; true; day++) {
		int test_sum = (pow(2, day) - 1) * x;

		if (sum == test_sum) {
			return true;
		} else if (test_sum > sum) {
			return false;
		}
	}

	return false;
}

int get_x(int sum) {
	for (int x = 1; true; x++) {
		if (test_x(x, sum)) {
			return x;
		}
	}

	return 0;
}

int main() {
	int sum[30] = {0}, T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> sum[i];
	}

	for (int i = 0; i < T; i++) {
		int one_sum = sum[i];
		int x = get_x(one_sum);
		if (x == 0) {
			cout << "not found" << endl;
		} else {
			cout << x << endl;
		}
	}

	return 0;
}
