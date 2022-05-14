#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

bool is_prime[10010];

int main() {
	int m, n;
	cin >> m >> n;
//	cout << "ddd" << endl;
	for (int i = 0; i <= n; i++)
		is_prime[i] = true;

	is_prime[0] = false;
	is_prime[1] = false;

	for (int i = 2; i <= n; i++) {
//		cout << "is prime of i =" << (is_prime[i] == true) << endl;
		if (is_prime[i] == true) {
//			cout << "prime --- " << i << endl;
			for (int j = 2 * i; j <= n; j += i ) {
//				cout << "set j not prime --- " << j << endl;
				is_prime[j] = false;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (is_prime[i] == true) {
//			cout << i << endl;

			int temp = i;
			bool is_lucky = true;
			while (temp / 10 > 0) {
				if (is_prime[temp / 10]) {
					temp = temp / 10;
				} else {
					is_lucky = false;
					break;
				}
			}

			if (is_lucky) {
				cout << i << endl;
			}
		}
	}
}