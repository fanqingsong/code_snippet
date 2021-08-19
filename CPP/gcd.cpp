#include <iostream>
using namespace std;
void show();

int x(int a, int b) {
	if (a == b)
		return a;
	else if (a > b)
		return x(a - b, b);
	else
		return x(a, b - a);
}

int main() {
	int i, j, k;
	cin >> i >> j >> k;
	i = x(i, j);
	i = x(i, k);
	cout << i << endl;
	show();
	return 0;
}

void show() {
	int a = 1;
	cout << a << endl;
}