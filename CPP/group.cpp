#include <bits/stdc++.h>
using namespace std;

bool finding_grp() {
	int n;
	cin >> n;
	int a[1000][5];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	bool cb[5] = {false};
	int ct = 0;
	for (int i = 0; i < 5; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (a[j][i]) {
				cnt++;
			}
		}
		if (cnt >= n / 2) {
			cb[i] = true;
//			cout << "===" << endl;
//			cout << i << endl;
			ct++;
		}
	}
//	cout << ct << endl;
	if (ct < 2) {
		return false;
	}
	for (int i = 0; i < 5; i++) {
		if (cb[i]) {
			for (int j = i + 1; j < 5; j++) {
				if (cb[j]) {
//					cout << i << j << endl;
					bool flag = false;
					for (int k = 0; k < n; k++) {
						if (!a[k][i] && !a[k][j]) {
							flag = true;
							break;
						}
					}

					if (flag == true) {
						continue;
					} else {
						return true;
					}
				}
			}
		}
	}

	return false;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		if (finding_grp()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}