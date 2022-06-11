#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int a[1005];
int x[1005][2];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; i++) {
		cin >> x[i][0];
		cin >> x[i][1];
	}
	long long mx = 0;
	for (int i = 0; i < n; i++) {
		int zx = x[i][0];
		int zy = x[i][1];
		long long mn = (long long)(pow(2, 62));
		for (int j = 0; j < k; j++) {
			int zx2 = x[a[j]][0];
			int zy2 = x[a[j]][1];
			mn = min(mn, (long long)(pow(abs(zx - zx2), 2)) + (long long)(pow(abs(zy - zy2), 2)));
		}
		mx = max(mx, mn);
	}
	printf("%f", sqrt(mx));
	return 0;
}