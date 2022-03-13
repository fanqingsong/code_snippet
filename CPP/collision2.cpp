#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/abc243/tasks/abc243_c
*/

#define LIMIT 200000

int main() {
	long n;
	long x[LIMIT] = {0};
	long y[LIMIT] = {0};
	char s[LIMIT];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i];
		cin >> y[i];
	}

	cin >> s;

	// search in y direction
	bool yflag[LIMIT] = {false};
	for (int yi = 0; yi < n - 1; yi++) {
		if (yflag[yi]) {
			continue;
		}

		for (int ayi = yi + 1; ayi < n; ayi++) {
			if (yflag[ayi]) {
				continue;
			}

			if (y[yi] == y[ayi]) {
				char first = s[yi];
				char second = s[ayi];

				if (x[yi] == x[ayi]) {
					// donothing
				} else if (x[yi] < x[ayi]) {
					if (first == 'R' && second == 'L') {
						cout << "Yes" << endl;
						return 0;
					}
				} else if (x[yi] > x[ayi]) {
					if (first == 'L' && second == 'R') {
						cout << "Yes" << endl;
						return 0;
					}
				}

				yflag[ayi] = true;
			}
		}

		yflag[yi] = true;
	}

	cout << "No" << endl;
}





