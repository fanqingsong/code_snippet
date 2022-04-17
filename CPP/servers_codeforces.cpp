#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <deque>
#include <string>
using namespace std;


/*
https://codeforces.com/problemset/problem/747/c
*/


struct TASK {
	int start_time;
	int num_machine;
	int last_time;

	// running state
	vector<int> machines;
	bool ignored;
	bool done;
};

int main() {
	int n, q;
	vector<struct TASK> tasks;

	cin >> n >> q;

	int num_free_machine = n;
	int num_tasks = q;

	int server_id[n];
	// using index from 1 to n, droping 0
	for (int i = 0; i <= n; i++)
		server_id[i] = i;

	// using index from 1 to n, droping 0
	bool server_used[n + 1] = {false};
	int server_overtime[n + 1] = {0};

	for (int i = 0; i < num_tasks; i++) {
		struct TASK one_task;
		one_task.ignored = false;
		one_task.done = false;

		cin >> one_task.start_time;
		cin >> one_task.num_machine;
		cin >> one_task.last_time;

		// refresh all previous task resources
		int current_time = one_task.start_time;
//		int tasks_size = (int) tasks.size();
//		for (int k = 0; k < tasks_size; k++) {
////			cout << "recycle task " << k << endl;
//			struct TASK &prev_task = tasks[k];
//			if (prev_task.ignored) {
//				continue;
//			}
//
//			if (prev_task.done) {
//				continue;
//			}
//
//			int done_time = prev_task.start_time + prev_task.last_time;
//			if (done_time <= current_time) {
//				prev_task.done = true;
//				for (auto server_id : prev_task.machines) {
//					server_used[server_id] = false;
//					num_free_machine ++;
//				}
//			}
//		}

		for (int k = 1; k <= n; k++) {
			if (server_used[k] == false) {
				continue;
			}

			if (server_overtime[k] <= current_time) {
				server_used[k] = false;
				server_overtime[k] = 0;
				num_free_machine ++;
			}
		}

		if (one_task.num_machine <= num_free_machine) {
			num_free_machine -= one_task.num_machine;

			int sum_id = 0;
			int machine_count = 0;
			for (int j = 1; j <= n; j++) {
//				cout << "-----------------" << server_used[j] << endl;
				if (server_used[j] == true) {
					continue;
				}

				server_used[j] = true;
				server_overtime[j] = one_task.start_time + one_task.last_time;

				one_task.machines.push_back(j);
				sum_id += server_id[j];

				machine_count ++;
				if (machine_count == one_task.num_machine) {
					break;
				}
			}
			cout << sum_id << endl;
		} else {
			one_task.ignored = true;
			cout << -1 << endl;
		}

		tasks.push_back(one_task);
	}

	return 0;
}

