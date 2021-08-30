#include <iostream>

using namespace std;

int calc_next(int num) {
	if (num % 2 == 0) {
		return num / 2;
	} else {
		return 3 * num + 1;
	}
}

int main() {
	int arr[1000] = {0};
	int index = 0;
	int s;

	cin >> s;

	arr[0] = s;

	while (true) {
		index ++;
		if (index > 1000) {
			break;
		}

		arr[index] = calc_next(arr[index - 1]);

		for (int i = 0; i < index; i++) {
			if (arr[i] == arr[index]) {
				cout << index + 1 << endl;
				return 0;
			}
		}
	}

	return 0;
}




