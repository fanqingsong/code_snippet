#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
https://atcoder.jp/contests/arc131/tasks/arc131_a
*/

unsigned long get_power(unsigned long num) {
	unsigned long power = 10;

	while (true) {
		num = num / 10;
		if (num > 0) {
			power *= 10;
		} else {
			break;
		}
	}

	return power;
}

bool is_small_in_big(unsigned long smallnum, unsigned long long bignum) {
	if (smallnum > bignum) {
		return false;
	}

	unsigned long power = get_power(smallnum);

	while (bignum > 0) {
		if ((bignum - smallnum) % power == 0) {
			return true;
		}

		bignum /= 10;
	}

	return false;
}

int main() {
	unsigned long a, b;

	cin >> a;
	cin >> b;

	unsigned long long x;
	unsigned long long power = get_power(b);
	unsigned long long iter;
	unsigned long long i;
	unsigned long long a_power;

	a_power = a * power;

	cout << (a_power * 2 + b) / 2 << endl;

//	while (true) {
//		iter = power;
//		a_power = a * power;
//		for (i = 0; i < iter; i++) {
//			x = a_power + i;
//			if (is_small_in_big(b, 2 * x)) {
//				cout << x << endl;
//				return 0;
//			}
//		}
//
//		power *= 10;
//	}
}


