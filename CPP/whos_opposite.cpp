#include <iostream>

using namespace std;

// https://codeforces.com/contest/1560/problem/B

int get_output(int onecase[3]) {
	int one_person = onecase[0];
	int its_opposite = onecase[1];

	int test_person = onecase[2];

//	cout << one_person << " " << its_opposite << " " << test_person << endl;

	int diff = 0;
	if (one_person > its_opposite) {
		diff = one_person - its_opposite;
	} else {
		diff = its_opposite - one_person;
	}
//	cout << diff << endl;

	// there is no person between one_person and its_opposite
	if (diff < 2) {
		return -1;
	}

	int max = 2 * diff;
	if (one_person > its_opposite) {
		if (one_person > max) {
			return -1;
		}
	} else {
		if (its_opposite > max) {
			return -1;
		}
	}

	if (test_person < 1) {
		return -1;
	}

	if (test_person > max) {
		return -1;
	}

	if (test_person + diff > max) {
		return (test_person + diff) % max;
	}

	return test_person + diff;
}

int main() {
	int count = 0;
	int testcase[100][3];

	cin >> count;

	for (int i = 0; i < count; i++) {
		cin >> testcase[i][0];
		cin >> testcase[i][1];
		cin >> testcase[i][2];
	}

	for (int i = 0; i < count; i++) {
		cout << get_output(testcase[i]) << endl;
	}
}
