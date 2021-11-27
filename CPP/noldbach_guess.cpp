#include <iostream>
using namespace std;

/*
https://codeforces.com/problemset/problem/17/A#:~:text=Since%20Nick%20is%20interested%20only%20in%20prime%20numbers%2C,or%2013%20%3D%205%20%2B%207%20%2B%201.
*/

int is_prime_num(int target) {
	int i = 0;

	if (target <= 1) {
		printf("illegal input!\n");
		return -1;
	}

	for (i = 2; i <= target / 2; i++) {
		if (target % i == 0) {
			return false;
		}
	}

	return true;
}

int find_next_prime(int current, int end) {
	int i = current + 1;
	for (; i <= end; i++) {
		if (is_prime_num(i)) {
			return i;
		}
	}

	return 0;
}

bool is_nold_num(int num) {
	if (!is_prime_num(num)) {
		return false;
	}

	int first = 2, second = 3;
	while (true) {
		if (first + second + 1 == num) {
			return true;
		}

		int next = find_next_prime(second, num - 1);
		if (next == 0) {
			break;
		}

		first = second;
		second = next;
	}

	return false;
}


int main() {
	int n, k;
	cin >> n >> k;

	if (n < 2 || n > 1000) {
		cout << "n input invalid." << endl;
		return -1;
	}

	if (k < 0 || k > 1000) {
		cout << "k input invalid." << endl;
		return -1;
	}

	int count = 0;
	for (int i = 2; i <= n; i++) {
		if (is_nold_num(i)) {
			count++;
		}
	}

	if (count >= k) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}






