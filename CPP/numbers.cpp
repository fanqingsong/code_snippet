#include <bits/stdc++.h>
using namespace std;

int main() {
	int aa, ans = 0;
	cin >> aa;
	for (int jj = 2; jj < aa; jj++) {
		int n, i, j = 0;
		int a[1000];
		i = aa;
		while (i) {
			a[j] = i % jj;
			i /= jj;
			j++;

		}
		for (int kk = j - 1; kk >= 0; kk--) {
			ans += a[kk];
		}
	}
	cout << ans << "/" << aa - 2 << endl;
}