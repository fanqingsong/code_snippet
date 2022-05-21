#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

int N;

int main() {
	cin >> N;

	int sum = 0;

	int middle = sqrt(N) + 1;
	for (int n = 1; n <= middle; n++) {
		if (N % n == 0) {
			sum += 2;
		}
	}

	cout << sum << endl;
}
