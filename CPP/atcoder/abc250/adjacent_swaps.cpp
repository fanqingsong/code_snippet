#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc250/tasks/abc250_c
*/

struct node {
	int prev;
	int next;
};

const int limit = 200010;

struct node balls[limit] = {
	{
		0, 0
	}
};

int main() {
	int n, q;

	cin >> n >> q;

	cout << to_string(n) << endl;

	// initialize n ball node prev and next
	// normally all previous and next pointer value must be in range [1, n]
	// but for first node, its previous pointer is 0
	// and for last node, its next pointer is n+1
	for (int i = 1; i <= n; i++) {
		balls[i].prev = i - 1;
		balls[i].next = i + 1;
	}

	for (int i = 0; i < q; i++) {
		int xi;
		cin >> xi;

		// need to swap curr_index and next_index
		int curr_index = xi;
		int next_index = balls[curr_index].next;

		// find two helping index
		int prev_index = balls[curr_index].prev;
		int next_next_index = balls[next_index].next;

		//
	}
}