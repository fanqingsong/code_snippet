#include <iostream>
using namespace std;

int solut(int n) {
	int s = n;
	for (int i = 1;; i++) {
		n = s;
		n /= i;
		n++;
		for (int y = 1;; y++) {
			if (n % 2 == 0) {
				n /= 2;
			} else {
				break;
			}
		}
		if (n == 1) {
			return i;
		}
	}
}

int main() {
	int i, n;
	cin >> i;
	for (int a = 0; a < i; a++) {
		cin >> n;
		cout << solut(n) << endl;

	}
	return 0;
}