#include <iostream>

using namespace std;

/*
https://codeforces.com/contest/1560/problem/A
*/

bool is_divisible_by_three(int num) {
	if (num % 3 == 0) {
		return true;
	}

	return false;
}

bool is_ended_with_three(int num) {
	if (num % 10 == 3) {
		return true;
	}

	return false;
}

int get_order_num(int order) {
	int count = 0;

	for (int i = 0; true; i++) {
		if (!is_divisible_by_three(i)
		        && !is_ended_with_three(i)) {
			count ++;
			if (count == order) {
				return i;
			}
		}
	}
}

int main() {
	int count;
	int nums[100];

	cin >> count;

	for (int i = 0; i < count; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < count; i++) {
		cout << get_order_num(nums[i]) << endl;
	}
}


