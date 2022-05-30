#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>

/*
http://go.helloworldroom.com:50080/problem/2723
*/

class Node {
	public:
		int pos;
		int steps;

	public:
		Node(int _pos, int _steps) {
			pos = _pos;
			steps = _steps;
		}

		bool operator<(const Node &nd) const {
			if (steps < nd.steps) {
				return true;
			} else {
				return false;
			}
		}

		bool operator>(const Node &nd) const {
			if (steps > nd.steps) {
				return true;
			} else {
				return false;
			}
		}
};


int get_huristic_steps(int src, int dst) {
	int pos = src;
	int target = dst;

	if (pos == target) {
		return 0;
	}

	if (pos < target) {
		int times = 0;
		int low_bound = pos;
		int up_bound = 0;

		while (true) {
			up_bound = 2 * low_bound;
			times++;

			if (target >= low_bound && target <= up_bound) {
				break;
			}

			low_bound = up_bound;
		}

		int dist_low = target - low_bound;
		int dist_up = up_bound - target;
		int dist = min(dist_low, dist_up);

		return times + dist;
	}

	if (pos > target) {
		return target - pos;
	}

	return INT_MAX;
}

int bfs(int src, int dst) {
	// smallest on head
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	set<int> closed;

	int limit = abs(src - dst);

	pq.push(Node(src, 0));

	while (!pq.empty()) {
		class Node nd = pq.top();
		pq.pop();

		int pos = nd.pos;
		int steps = nd.steps;

//		cout << "pos = " << pos << endl;
//		cout << "steps = " << steps << endl;

		if (pos == dst) {
//			cout << "found steps=" << steps << endl;
			return steps;
		}

		closed.insert(pos);

		if (closed.find(pos - 1) == closed.end() ) {
			if (steps + 1 <= limit) {
				pq.push(Node(pos - 1, steps + 1));
			}
		}

		if (closed.find(pos + 1) == closed.end()) {
			if (steps + 1 <= limit) {
				pq.push(Node(pos + 1, steps + 1));
			}
		}

		/*
		only if pos is in left of dst, then 2 * x can be one option
		*/
		if (pos < dst) {
			if (closed.find(2 * pos) == closed.end()) {
				if (steps + 1 <= limit) {
					pq.push(Node(pos * 2, steps + 1));
				}
			}
		}
	}
}


int main() {
	int x, y;

	cin >> x >> y;

	int ans = bfs(x, y);

	cout << ans << endl;

	return 0;
}
