#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;

/*
https://codeforces.com/problemset/problem/1374/C
*/



int get_move_num(string temp, int n) {
	stack<char> st;

	for (int i = 0; i < n; i++) {
		char current = temp[i];

		if (current == ')') {
			if (st.size() > 0) {
				char top = st.top();

				if (top == '(') {
					st.pop();
				} else {
					st.push(current);
				}
			} else {
				st.push(current);
			}
		} else {
			st.push(current);
		}
	}

	int size = st.size();

	return size / 2;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		string temp;

		cin >> n;
		cin >> temp;

		int ans = get_move_num(temp, n);

		cout << ans << endl;
	}
}
