#include <iostream>
#include <cmath>

using namespace std;

int delete_zero(int num) {
	int num_nozero = 0;
	int power = 0;
	int quotient = 0;
	int remainder = 0;
	int dividend = num;

	while (true) {
		remainder = dividend % 10;
		quotient = dividend / 10;

		if (remainder != 0) {
			num_nozero += remainder * pow(10, power);
			power ++;
		}

		dividend = quotient;

		if (dividend == 0) {
			break;
		}
	}

	return num_nozero;
}

int main() {
	int a, b, sum;
	int a_nozero, b_nozero, sum_nozero;

	while (true) {
		cout << "please input a([1, 10**9]):" << endl;

		cin >> a;

		if (a >= 1 && a <= pow(10, 9)) {
			break;
		}

		cout << "your input is invalid, please input again.";
	}

	while (true) {
		cout << "please input b([1, 10**9]):" << endl;

		cin >> b;

		if (b >= 1 && b <= pow(10, 9)) {
			break;
		}

		cout << "your input is invalid, please input again.";
	}


	sum = a + b;

	a_nozero = delete_zero(a);
	b_nozero = delete_zero(b);
	sum_nozero = delete_zero(sum);

	if (a_nozero + b_nozero == sum_nozero) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}


