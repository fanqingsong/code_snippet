#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <stack>

/*
https://atcoder.jp/contests/abc259/tasks/abc259_a
*/

int main() {
	int n, m, x, t, d;

	cin >> n  >> m >> x >> t >> d;

	if (m>x && m<=n){
		cout << t << endl;
	} else if (m>=0 && m<=x){
		cout << t - d*(x-m) << endl;
	}

	return 0;
}
