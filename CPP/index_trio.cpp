#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc249/tasks/abc249_d
*/

#define MAX_CONTAINER (200000 + 12)
#define MAX 200000

int main() {
	int64_t n;
	int64_t counter[MAX_CONTAINER] = {0};

	cin >> n;

	for (int i = 0; i < n; i++) {
		int key;
		cin >> key;

		counter[key]++;
	}

	int64_t count = 0;

	for (int i = 1; i <= MAX;  i++) {
		for (int j = 1; j <= MAX / i; j++) {
			int64_t prod_index = i * j;
			count += counter[i] * counter[j] * counter[prod_index];
		}
	}

	cout << count << endl;

	return 0;
}


