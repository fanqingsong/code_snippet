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

//	cout << to_string(n) << endl;

	// initialize n ball node prev and next
	// normally all previous and next pointer value must be in range [1, n]
	// but for first node, its previous pointer is 0, called head
	// and for last node, its next pointer is n+1, called tail
	int head_index = 0;
	int tail_index = n + 1;
	balls[head_index].next = 1;
	balls[tail_index].prev = n;

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

		int prev_index = 0;
		int next_next_index = 0;

		// current ball is the last ball,
		// set curr_index as n-2, next_index as n-1
		if (next_index == tail_index) {
			int prev_curr_index = balls[curr_index].prev;
			next_index = curr_index;
			curr_index = prev_curr_index;
		}

		// find two helping index
		prev_index = balls[curr_index].prev;
		next_next_index = balls[next_index].next;

		//swap curr and next
		balls[prev_index].next = next_index;
		balls[next_next_index].prev = curr_index;

		balls[curr_index].prev = next_index;
		balls[curr_index].next = next_next_index;

		balls[next_index].prev = prev_index;
		balls[next_index].next = curr_index;
	}

	// print
	int curr_index = balls[head_index].next;
	while (curr_index != tail_index) {
		cout << curr_index;
		curr_index = balls[curr_index].next;

		if (curr_index != tail_index) {
			cout << " ";
		}
	}
}