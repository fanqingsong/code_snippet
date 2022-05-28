// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>


int factorial(int n) {
	if (n == 1) {
		return 1;
	}

	return factorial(n - 1) * n;
}


// driver program to test above function
int main() {
	int N;

	cin >> N;

	int ans = factorial(N);

	cout << ans << endl;
	return 0;
}
