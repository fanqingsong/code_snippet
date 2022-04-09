#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;


/*
https://atcoder.jp/contests/abc246/tasks/abc246_a
*/

int main() {
	int x1, y1;
	int x2, y2;
	int x3, y3;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	int x4, y4;

	if (x1 == x2) {
		if (y3 == y1) {
			/*
			(x1, y1)	(x3, y3)
			(x2, y2)	(x4, y4)
			*/
			x4 = x3;
			y4 = y2;
		} else if (y3 == y2) {
			/*
			(x1, y1)	(x4, y4)
			(x2, y2)	(x3, y3)
			*/
			x4 = x3;
			y4 = y1;
		}
	} else if (x1 == x3) {
		if (y2 == y1) {
			/*
			(x1, y1)	(x2, y2)
			(x3, y3)	(x4, y4)
			*/
			x4 = x2;
			y4 = y3;
		} else if (y2 == y3) {
			/*
			(x1, y1)	(x4, y4)
			(x3, y3)	(x2, y2)
			*/
			x4 = x2;
			y4 = y1;
		}
	} else if (x2 == x3) {
		if (y1 == y2) {
			/*
			(x3, y3)	(x4, y4)
			(x2, y2)	(x1, y1)
			*/
			x4 = x1;
			y4 = y3;
		} else if (y1 == y3) {
			/*
			(x3, y3)	(x1, y1)
			(x2, y2)	(x4, y4)
			*/
			x4 = x1;
			y4 = y2;
		}
	}

	cout << x4 << " " << y4 << endl;

	return 0;
}
