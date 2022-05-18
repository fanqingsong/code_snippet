#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
https://codeforces.com/problemset/problem/1680/B
*/

int main() {
	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;

		bool rc[5][5] = {{false}};
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				char pos;
				cin >> pos;
				if (pos == 'E') {
					rc[j][k] = false;
				} else if (pos == 'R') {
					rc[j][k] = true;
				}
			}
		}

		// search first row where R appears at first time
		int frr_index, frr_rc_index;
		for (int j = 0; j < n; j++) {
			bool r_found = false;
			for (int k = 0; k < m; k++) {
				if (rc[j][k] == true) {
					r_found = true;
					frr_index = j;
					frr_rc_index = k;
					break;
				}
			}

			if (r_found == true) {
				break;
			}
		}

		// search first colomun where R appears at first time
		int frc_index, frc_rr_index;
		for (int k = 0; k < m; k++) {
			bool r_found = false;
			for (int j = 0; j < n; j++) {
				if (rc[j][k] == true) {
					r_found = true;
					frc_index = k;
					frc_rr_index = j;
					break;
				}
			}

			if (r_found == true) {
				break;
			}
		}

		if (frr_index == frc_rr_index && frc_index == frr_rc_index) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}
