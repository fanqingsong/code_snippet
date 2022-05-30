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
		int target;

	public:
		Node(int _pos, int _steps, int _target) {
			pos = _pos;
			steps = _steps;
			target = _target;
		}

		int get_huristic_steps() const {
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
						cout << "low_bound = " << low_bound << endl;
						cout << "up_bound = " << up_bound << endl;
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

		bool operator<(const Node &nd) const {
			int huristic_steps = steps + get_huristic_steps();
			int nd_huristic_steps = nd.steps + nd.get_huristic_steps();

			if (huristic_steps > nd_huristic_steps) {
				return true;
			} else {
				return false;
			}
		}
};

int bfs(int src, int dst) {
	priority_queue<Node> pq;
	set<int> closed;
	set<int> solutions;

	int solution_max = 1;
	int solution_count = 0;

	pq.push(Node(src, 0, dst));
	while (!pq.empty()) {
		class Node nd = pq.top();
		pq.pop();

		int pos = nd.pos;
		int steps = nd.steps;

		cout << "pos = " << pos << endl;
		cout << "steps = " << steps << endl;

		if (pos == dst) {
			cout << "found steps=" << steps << endl;
//			return steps;
			solutions.insert(steps);

			solution_count++;

			if (solution_count >= solution_max) {
				break;
			}
		}

		closed.insert(pos);

		if (closed.find(pos - 1) == closed.end()) {
			pq.push(Node(pos - 1, steps + 1, dst));
		}

		if (closed.find(pos + 1) == closed.end()) {
			pq.push(Node(pos + 1, steps + 1, dst));
		}

		if (closed.find(2 * pos) == closed.end()) {
			pq.push(Node(2 * pos, steps + 1, dst));
		}
	}

	set<int>::iterator it;
	for (it = solutions.begin(); it != solutions.end(); it++) {
		cout << "solution = " << *it << endl;
	}

	return *solutions.begin();
}


int main() {
	int x, y;

	cin >> x >> y;

	int ans = bfs(x, y);

	cout << ans << endl;

	return 0;
}
