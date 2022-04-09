
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <deque>
using namespace std;


/*
http://poj.org/problem?id=2431

reference:
https://www.programminghunter.com/article/61121428339/
*/


struct node {
	int distance;
	int fuel;
};

int main() {
	int N;
	vector<node> stops;
	int L, P;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int d, f;
		cin >> d;
		cin >> f;

		struct node one_stop;
		one_stop.distance = d;
		one_stop.fuel = f;

		stops.push_back(one_stop);
	}

	cin >> L >> P;

//	cout << L << "  " << P << endl;

	int l_left = L;
	int tank = P;
	int steps = 0;

	priority_queue<int> pq;

	for (int i = N - 1; i >= 0; i--) {
		struct node one_stop = stops[i];
		int distance = one_stop.distance;
		int fuel = one_stop.fuel;

//		cout << "distance= " << distance << endl;
//		cout << "fuel= " << fuel << endl;

		int l_diff = l_left - distance;
		while (tank < l_diff) {
			if (pq.empty()) {
				cout << -1 << endl;
				return 0;
			}

			int top = pq.top();
			tank += top;
			pq.pop();
			steps ++;
		}

		tank -= l_diff;
		l_left -= l_diff;

		pq.push(fuel);
	}

	cout << steps << endl;

	return 0;
}