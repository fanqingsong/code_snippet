// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>

/*
https://atcoder.jp/contests/abc253/tasks/abc253_b
*/

bool matrix[102][102] = {{false}};

// driver program to test above function
int main() {
	int H, W;

	cin >> H >> W;

	vector<int> hset;
	vector<int> wset;

	for (int h = 1; h <= H; h++ ) {
		string temp;
		cin >> temp;

		for (int w = 1; w <= W; w++) {
			char one = temp[w - 1];
			if (one == 'o') {
				matrix[h][w] = true;
				hset.push_back(h);
				wset.push_back(w);
			} else if (one == '-') {
				matrix[h][w] = false;
			}
		}
	}

	int diff_h = abs(hset[1] - hset[0]);
	int diff_w = abs(wset[1] - wset[0]);

	int sum = diff_h + diff_w;
	cout << sum << endl;

	return 0;
}
