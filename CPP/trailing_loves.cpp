#include <iostream>

using namespace std;

//https://codeforces.com/problemset/problem/1114/C

int main() {
	int n, b;

	cin >> n;
	cin >> b;

	int factorial = 1;
	for (int i = 1; i <= n; i++) {
		factorial *= i;
	}

//	cout << factorial << endl;

	int number_b_index = 0;
	int power = 1;
	int remainder = 0;
	int quotion = 0;

	bool trail_flag = true;
	int count = 0;

	while (true) {
		int remainder = factorial % b;
		int quotion = factorial / b;

		if (trail_flag) {
			if (remainder == 0) {
				count ++;
			} else {
				trail_flag = false;
			}
		}

		number_b_index += remainder * power;

		if (quotion == 0) {
			break;
		}

		power *= 10;
		factorial = quotion;
	}

//	cout << number_b_index << endl;

	cout << count << endl;
}