#include <iostream>
using namespace std;

int main() {
	int a[10], b, c, d, e, f, g, h;
	cin >> b >> a[0];
	for (c = 1; c <= b; c++) {
		cin >> a[c];
	}
	if (b <= a[0]) {
		for (c = 1; c <= b; c++) {
			d += a[c];
		}
		cout << d << endl;
	} else {
		for (c = 1; c <= a[0]; c++) {
			d += a[c];
		}
		b -= a[0];
		for (c = 1; b > a[0]; c++) {
			e = a[0] * c;
			d += a[e];
			b -= a[0];
		}

		for (c = 1; c < b; b--) {
			g = e + b;
			d += a[g];
		}
		cout << d << endl;
	}
	return 0;
}