#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>

/*
https://atcoder.jp/contests/abc257/tasks/abc257_a
*/

int main() {

	int n, x;
	
	cin >> n >> x;
	
	int quotient = x / n;
	int remainder = x % n;
	
	int index = quotient;
	if (remainder > 0) {
		index ++;
	}

	cout << char('A' + index - 1) << endl;

	return 0;
}
