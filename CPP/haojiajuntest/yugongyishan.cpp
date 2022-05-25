#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

int N;
int f[202][202] = {{0}};

int main() {
	cin >> N;

	// n rocks are in one column
	for (int n = 1; n <= N; n++) {
		f[n][1] = 1;
	}

	// 1 rock is with any number of columns
	for (int m = 2; m <= N; m++) {
		f[1][m] = 0;
	}

	// column is increasing
	for (int m = 2; m <= N; m++) {
		for (int n = 2; n <= N; n++) {
			f[n][m] = 0;


			int a1_max = n / m;
			for (int k = 1; k <= a1_max; k++) {
				int left_n = n - m * k;
				f[n][m] += f[left_n][m - 1];
			}
		}
	}

//	cout << endl;
//	cout << "----------------------------";
//	for (int n = 1; n <= N; n++) {
//		for (int m = 1; m <= N; m++) {
//			cout << f[n][m] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;

	int count = 0;
	for (int m = 2; m <= N; m++) {
//		cout << "m == " << m << " " << f[N][m] << endl;
		count += f[N][m];
	}

	cout << count << endl;
}
