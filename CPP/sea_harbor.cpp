
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;


/*
https://www.luogu.com.cn/problem/P2058
*/

struct SHIP {
	int reach_second;
	int customer_num;
	vector<int> nationality;
};


int nationality_counter[1000005] = {0};
int ans = 0;


int main() {
	int N;
	vector<SHIP> shiplist;

	cin >> N;

	// for watching ships in the latest one hour
	deque<int> slide_window;

	for (int i = 0; i < N; i++) {
		SHIP one_ship;

		cin >> one_ship.reach_second;
		cin >> one_ship.customer_num;

		for (int j = 0; j < one_ship.customer_num; j++) {
			int temp;
			cin >> temp;
			one_ship.nationality.push_back(temp);

			nationality_counter[temp] ++;
			if (nationality_counter[temp] == 1) {
				ans++;
			}
		}

		shiplist.push_back(one_ship);

		// input i ship into slide window
		slide_window.push_back(i);

		// quit expired ship
		SHIP &current_ship = shiplist[i];
		int current_time = current_ship.reach_second;
		int expired_time = current_time - 86400;

		while (true) {
			int soonest_index = slide_window.front();
			if (soonest_index < i) {
				SHIP &soonest_ship = shiplist[soonest_index];
				int soonest_time = soonest_ship.reach_second;
				if (soonest_time <= expired_time) {
					slide_window.pop_front();
					vector<int> &nationality = soonest_ship.nationality;
					for (int i = 0; i < nationality.size(); i++) {
						int nation_index = nationality[i];
						nationality_counter[nation_index] --;
						if (nationality_counter[nation_index] == 0) {
							ans--;
						}
					}
				} else {
					break;
				}
			} else {
				break;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
