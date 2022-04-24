#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://atcoder.jp/contests/abc249/tasks/abc249_a
*/


int main() {
	int A, B, C, D, E, F, X;

	cin >> B >> A >> C >> E >> D >> F >> X;

	// A m/s for B , rest C s

	int t_times = X / (B + C);
	int t_remainder = X % (B + C);
	int t_length = 0;

	t_length += t_times * A * B;

	int t_secs = 0;
	if (t_remainder <= B) {
		t_secs = t_remainder;
	} else {
		t_secs = B;
	}

	t_length += t_secs * A;


	// D m/s for E , rest F s
	int a_times = X / (E + F);
	int a_remainder = X % (E + F);
	int a_length = 0;

	a_length += a_times * D * E;

	int a_secs = 0;
	if (a_remainder <= E) {
		a_secs = a_remainder;
	} else {
		a_secs = E;
	}

	a_length += a_secs * D;


	if (t_length == a_length) {
		cout << "Draw" << endl;
	} else if (t_length > a_length) {
		cout << "Takahashi" << endl;
	} else {
		cout << "Aoki" << endl;
	}

	return 0;
}


