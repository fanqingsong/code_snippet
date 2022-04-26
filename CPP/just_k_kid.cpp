#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, kk;
	cin >> n >> kk;
	bool appr[15][26] = {{false}};
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < (int)s.size(); j++) {
			appr[i][s[j] - 'a'] = true;
		}
	}
	int ans = 0;
	int cont = 1;
	for (int i = 0; i < n; i++) {
		cont *= 2;
	}
	for (int i = 1; i < cont; i++) {
//		cout << "************ i=" << i << endl;
		bool used[15] = {false};
		for (int j = 0; j < n; j++) {
			if ((i >> j) % 2 == 1) {
//				cout << " == " << j << endl;
				used[j] = true;
			}
		}
//		cout << "------------------" << endl;
		int ans1 = 0;
		for (int k = 0; k < 26; k++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (used[j]) {
					cnt += appr[j][k];
				}
			}
			if (cnt == kk) {
				ans1++;
			}
		}
		ans = max(ans, ans1);
	}
	cout << ans << endl;
	return 0;
}