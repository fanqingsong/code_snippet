#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num) {
	for (int i = 2; i < num - 1; i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

int search_all_primes(int n, int *primes) {
	int count = 0;

	for (int i = 2; i <= n; i++ ) {
		if (is_prime(i)) {
			primes[count] = i;
			count++;
		}
	}

	return count;
}

int main() {
	int n, k;
	int primes[1000] = {0};
	int count = 0;
	int count_k = 0;

	while (true) {
		cout << "please input n([2, 1000]):" << endl;

		cin >> n;

		if (n >= 2 && n <= pow(10, 3)) {
			break;
		}

		cout << "your input is invalid, please input again.";
	}


	while (true) {
		cout << "please input k([0, 1000]):" << endl;

		cin >> k;

		if (k >= 2 && k <= pow(10, 3)) {
			break;
		}

		cout << "your input is invalid, please input again.";
	}

	count = search_all_primes(n, primes);

	for (int i = 2; i < count; i++) {
		int target = primes[i];

		for (int j = 1; j < i; j++) {
			int prime1 = primes[j - 1];
			int prime2 = primes[j];

			if (prime1 + prime2 + 1 == target) {
				count_k ++;
				break;
			}
		}
	}

//	cout << "count_k" << count_k << endl;

	if (k == count_k) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}