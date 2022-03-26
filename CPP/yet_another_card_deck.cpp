#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t >> n;
	vector<int> v;
	vector<int> ve;
	int j;
	for (int i = 0; i < t; i++) {
		cin >> j;
		v.push_back(j);

	}
	for (int i = 0; i < n; i++) {
		int tt = 0;
		cin >> j;
		for (int k = 0; k < t; k++) {
			if (v[k] == -1) {
				tt++;
			}
			if (v[k] == j) {
				cout << k - tt + 1 << " ";
				v.push_back(v[k]);
				v[k] = -1;
				break;
			}
		}
	}
	cout << endl;

}