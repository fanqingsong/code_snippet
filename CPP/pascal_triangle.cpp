#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int previous[100] = {0};
	int current[100] = {0};

	previous[1] = 1;
	previous[2] = 1;

	int level = 3;

	cout << "please intput level that you want." << endl;
	cin >> level;

	cout << "level you inputted =" << level << endl;

	for (int i = 3; i <= level; i++) {
		current[1] = 1;

		for (int j = 2; j <= i - 1; j++) {
			current[j] = previous[j] + previous[j - 1];
		}

		current[i] = 1;

		for (int k = 1; k <= i; k++) {
			previous[k] = current[k];
		}
	}

	// print
	for (int k = 1; k <= level; k++) {
		cout << setw(3) << current[k];
	}
	cout << endl;

	return 0;
}