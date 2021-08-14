#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

bool search(int ordArr[], int low, int high, int target) {
	if (low > high) {
		return false;
	}

	int middle = (low + high) / 2;

	int midVal = ordArr[middle];
	if (target == midVal) {
		return true;
	} else if (target < midVal) {
		return search(ordArr, low, middle - 1, target);
	} else if (target > midVal) {
		return search(ordArr, middle + 1, high, target);
	}
}

bool search_for(int ordArr[], int low, int high, int target) {
	if (low > high) {
		return false;
	}

	for(;low<=high;){
		int middle = (low + high) / 2;
		int midVal = ordArr[middle];

		if (target == midVal) {
			return true;
		} else if (target < midVal) {
			high = middle - 1;
		} else if (target > midVal) {
			low = middle + 1;
		}
	}

	return false;
}

int main() {
	int ordArr[5] = {10, 20, 30, 40, 50};
	int target = 0;

	cout << "please input target for finding" << endl;

	cin >> target;

	if (search(ordArr, 0, 4, target)) {
		cout << "found" << endl;
	} else {
		cout << "not found" << endl;
	}

	if (search_for(ordArr, 0, 4, target)) {
		cout << "found" << endl;
	} else {
		cout << "not found" << endl;
	}

	return 0;
}