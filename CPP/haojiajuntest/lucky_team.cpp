#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

int T;
int N;
bool lucky[3000];


int main() {

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		for (int n = 1; n <= N - 1; n++) {
			lucky[n] = false;
		}

		int prev;
		cin >> prev;

		int curr;
		bool is_lucky = true;
		for (int n = 1; n <= N - 1; n++) {
			cin >> curr;

			int diff = abs(curr - prev);
			if (diff < 1 || diff > N - 1) {
				cout << "Thanks" << endl;
			}

			if (lucky[diff] == false) {
				lucky[diff] = true;
			} else {
				cout << "Thanks" << endl;
				is_lucky = false;
				break;
			}
		}

		if (is_lucky) {
			cout << "Lucky" << endl;
		}
	}
}
