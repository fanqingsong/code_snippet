// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>

string to_bin(int n) {
	if (n == 1) {
		return "1";
	} else if (n == 0) {
		return "0";
	}

	int remainder = n % 2;
	int times = n / 2;

	if (remainder == 1) {
		return to_bin(times) + "1";
	} else if (remainder == 0) {
		return to_bin(times) + "0";
	}
}

// driver program to test above function
int main() {
	int N;

	cin >> N;

	string binstr = to_bin(N);

	cout << binstr << endl;

	return 0;
}
