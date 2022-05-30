// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>

/*
https://atcoder.jp/contests/abc253/tasks/abc253_a
*/

// driver program to test above function
int main() {
	int a, b, c;

	cin >> a >> b >> c;

	if (b >= a && b <= c || b >= c && b <= a ) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}
