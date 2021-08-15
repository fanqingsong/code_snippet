#include <iostream>

using namespace std;

bool is_prime(int num) {
	for (int i = 2; i < num - 1; i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

bool is_super_prime(int num) {
	do {
		if (!is_prime(num)) {
			return false;
		}
		num = num / 10;
	} while (num > 0);

	return true;
}

int main() {
//	int upper;
//
//	cout << "input the upper num:" << endl;
//	cin >> upper;

	for (int i = 100; i <= 999; i++) {
		if (is_super_prime(i)) {
			cout << i << endl;
		}
	}
	return 0;
}


