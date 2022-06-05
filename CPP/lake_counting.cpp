#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
http://poj.org/problem?id=2386
*/

bool wfields[102][102] = {{false}};

bool visited[102][102] = {{false}};
int n, m;


void dfs(int i, int j) {
	if (i < 1 || i > n ) {
//		cout << "i is out of bound. i=" << i << endl;
		return;
	}

	if (j < 1 || j > m) {
//		cout << "j is out of bound. j=" << j << endl;
		return;
	}

	if (visited[i][j] == true) {
		return ;
	} else {
		visited[i][j] = true;
	}

	if (wfields[i][j] == false) {
//		cout << "water fields is false." << endl;
		return;
	}

	for (int diff_i = -1; diff_i <= 1; diff_i++) {
		for (int diff_j = -1; diff_j <= 1; diff_j++) {
			dfs(i + diff_i, j + diff_j);
		}
	}
}


int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;

		for (int j = 1; j <= m; j++) {
			if (temp[j - 1] == 'W') {
				wfields[i][j] = true;
			} else {
				wfields[i][j] = false;
			}

			visited[i][j] = false;
		}
	}

	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (wfields[i][j] == true && visited[i][j] == false) {
				count ++;

				dfs(i, j);
			}
		}
	}

	cout << count << endl;
}
