#include <iostream>
#include <cmath>

using namespace std;


int main() {
	char str[200000] = {0};

	cin >> str;

	int count_prev = 0;
	int count = 0;

	while (true) {
		count_prev = count;

		for (int i = 2; i < strlen(str); i++) {
			if (str[i - 2] == 'A' && str[i - 1] == 'B' && str[i] == 'C') {
				str[i - 2] = 'B';
				str[i - 1] = 'C';
				str[i] = 'A';

				count++;
			}
		}

		if (count_prev == count) {
			break;
		}
	}

	cout << count << endl;
}
