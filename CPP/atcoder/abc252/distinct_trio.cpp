#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
https://atcoder.jp/contests/abc252/tasks/abc252_d
*/

int N;
int A[200008];
map<int, int> mp;

/*
https://blog.csdn.net/a2824256/article/details/112577268
*/
vector<int> get_keys(map<int, int> mp) {
	vector<int> keys;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		keys.push_back(it->first);
	}

	return keys;
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		mp[A[i]] ++;
	}

	int sum = 0;

	vector<int> keys = get_keys(mp);
	int size = keys.size();
	for (int i = 0; i < size; i++) {
		int keyi = keys[i];
		int vali = mp[keyi];

		for (int j = i + 1; j < size; j++) {
			int keyj = keys[j];
			int valj = mp[keyj];

			int valij = vali * valj;

			for (int k = j + 1; k < size; k++) {
				int keyk = keys[k];
				int valk = mp[keyk];

				sum += valij * mp[keyk];
			}
		}
	}

	cout << sum << endl;
}
