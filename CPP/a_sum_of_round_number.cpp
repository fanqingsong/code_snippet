#include <iostream>

using namespace std;

// https://codeforces.com/contest/1352/problem/A

int parse_round_nums(int num, int round_nums[50]) {
	int power = 1;
	int count = 0;
	int remainder = 0;

	while (true) {

		remainder = num % 10;
		if (remainder != 0) {
			round_nums[count] = remainder * power;
			count ++;
		}

		num = num / 10;

		power *= 10;

		if (num <= 0) {
			break;
		}
	}

	return count;
}

int main() {
	int count = 0;
	int nums[100] = {0};
	int round_count = 0;
	int round_nums[50] = {0};

	cin >> count;

	for (int i = 0; i < count; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < count; i++) {
		round_count = parse_round_nums(nums[i], round_nums);

		cout << round_count << endl;

		if (round_count > 0) {
			for (int i = 0; i < round_count; i++) {
				cout << round_nums[i] << " ";
			}
			cout << endl;
		}
	}
}

