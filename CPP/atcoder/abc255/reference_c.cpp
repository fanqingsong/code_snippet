#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long x, a, d, n;
	cin >> x >> a >> d >> n;
	long long mn = a;
	long long mx = a + d * (n - 1);
	if (mn > mx)
		swap(mn, mx);
	if (x < mn) {
		cout << mn - x;
		return 0;
	}
	if (x > mx) {
		cout << x - mx;
		return 0;
	}
	long long cha = abs(x - a);
	bool bo = 0;
	if (d < 0) {
		d = -d;
		bo = 1;
	}
	long long cs = 0;
	if (d != 0)
		cs = cha / d;
	if (bo)
		d = -d;
	long long nu1 = a + d * cs;
	long long nu2 = a + d * (cs + 1);
	cout << min(abs(nu1 - x), abs(nu2 - x));
	return 0;
}