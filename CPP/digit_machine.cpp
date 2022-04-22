#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc241/tasks/abc241_a
*/


int main() {
	int arr[10];

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	int count = 3;
	int index = 0;
	int val = 0;
	while (count > 0) {
		val = arr[index];
		index = val;
		count--;
	}

	cout << val << endl;
}


