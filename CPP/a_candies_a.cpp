#include <iostream>

using namespace std;

// https://codeforces.com/contest/1343/problem/A

int get_possible_x(int candies_num) {
	// x+2x+4x+?+2k-1x=n
	int coefficient = 0;
	coefficient = 1;

	int acc_two_product = 1;
	for (int k = 2; ; k++) {
		acc_two_product *= 2;

		coefficient += acc_two_product;

		if (candies_num % coefficient == 0) {
			return candies_num / coefficient;
		}

		if (coefficient > candies_num) {
			return -1;
		}
	}
}

int main() {
	int count = 0;
	int candies[100] = {0};

	cin >> count;

	for (int i = 0; i < count; i++) {
		cin >> candies[i];
	}

	for (int i = 0; i < count; i++) {
		cout << get_possible_x(candies[i]) << endl;
	}
}



