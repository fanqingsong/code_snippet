#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <set>

/*
https://atcoder.jp/contests/abc255/tasks/abc255_b
*/

int n, k;
int x[1001];
int y[1001];

set<int> lights;

set<int> unlighted;


// driver program to test above function
int main() {
	cin >> n >> k;

	// for light assignment
	for (int i = 1; i <= k; i++) {
		int pos;
		cin >> pos;

		lights.insert(pos);
	}

//	set<int>::iterator it;
//	cout << " ------- start" << endl;
//	for (it = lights.begin(); it != lights.end(); it++) {
//		cout << * it << endl;
//	}
//	cout << " ------- end" << endl;


	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];

		if (lights.count(i) == 0) {
			unlighted.insert(i);
		}
	}

//	cout << " ------- start" << endl;
//	for (it = unlighted.begin(); it != unlighted.end(); it++) {
//		cout << * it << endl;
//	}
//	cout << " ------- end" << endl;


	long long minimum_strength = 0;

	set<int>::iterator it;
	for (it = unlighted.begin(); it != unlighted.end(); it++) {
		int person_pos = *it;

		int person_x = x[person_pos];
		int person_y = y[person_pos];

		long long nearest_light_dist = LLONG_MAX;

		set<int>::iterator it2;
		for (it2 = lights.begin(); it2 != lights.end(); it2++) {
			int light_pos = *it2;

			int light_x = x[light_pos];
			int light_y = y[light_pos];

			long long diff_x = abs(light_x - person_x);
			long long diff_y = abs(light_y - person_y);

//			cout << "diff_x = " << diff_x << endl;
//			cout << "diff_y = " << diff_y << endl;


//			cout << "diff_y * diff_y = " << diff_y *diff_y << endl;
			long long dist = diff_x * diff_x + diff_y * diff_y;

//			cout << "dist = " << dist << endl;

			if (nearest_light_dist > dist) {
				nearest_light_dist = dist;
			}
		}

		if (minimum_strength < nearest_light_dist) {
			minimum_strength = nearest_light_dist;
		}
	}

//	cout << minimum_strength << endl;
	cout << sqrt(minimum_strength) << endl;

	return 0;
}
