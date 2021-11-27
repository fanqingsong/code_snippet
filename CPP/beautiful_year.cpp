#include <iostream>
using namespace std;

/*
https://codeforces.com/problemset/problem/271/A
*/

bool is_all_digits_distinct(int num) {
	// 2013
	int first_digit = num / 1000;

	num = num % 1000;
	int second_digit = num / 100;

	num = num % 100;
	int third_digit = num / 10;

	int fourth_digit = num % 10;

	if (first_digit != second_digit
	        && first_digit != third_digit
	        && first_digit != fourth_digit
	        && second_digit != third_digit
	        && second_digit != fourth_digit
	        && third_digit != fourth_digit) {
		return true;
	}

	return false;
}

int main() {
	int num;
	cin >> num;

	if (num < 1000 || num > 9000) {
		cout << "input invalid." << endl;
		return -1;
	}

	while (true) {
		num++;
		if (is_all_digits_distinct(num)) {
			cout << num << endl;
			break;
		}
	}

	return 0;
}



