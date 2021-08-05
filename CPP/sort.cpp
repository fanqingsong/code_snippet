#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int len = 0;
	int numArr[100] = {0};

	cout << "Please enter the total of numbers." << endl;
	cin >> len;

	for (int i = 0; i < len; i++) {
		cout << "The " << i << "th number:" << endl;
		cin >> numArr[i];
		//cout << numArr[i] << endl;
	}

	cout << "inputed arr:" << endl;
	for (int i = 0; i < len; i++) {
		cout << setw(5) << numArr[i];
	}
	cout << endl;

	for (int i = len - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			if (numArr[j] > numArr[j + 1]) {
				int temp = numArr[j];
				numArr[j] = numArr[j + 1];
				numArr[j + 1] = temp;
			}
		}
	}

	cout << "sorted arr:" << endl;
	for (int i = 0; i < len; i++) {
		cout << setw(5) << numArr[i];
	}
	cout << endl;

	return 0;
}