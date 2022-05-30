// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>


int gcd(int m, int n) {
	if (m == 0) {
		return n;
	}

	if (n == 0) {
		return m;
	}

	if (m >= n) {
		int temp = m % n;
		m = n;
		n = temp;

		return gcd(m, n);
	}

	if (m <= n) {
		int temp = n % m;
		n = m;
		m = temp;

		return gcd(m, n);
	}

	return 0;
}

// driver program to test above function
int main() {
	int m, n;

	cin >> m >> n;

	int ans = gcd(m, n);

	cout << ans << endl;

	cout << m / ans *n << endl;

	return 0;
}
