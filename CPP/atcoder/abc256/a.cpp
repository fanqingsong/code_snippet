#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>

/*
https://atcoder.jp/contests/abc256/tasks/abc256_a
*/


int main() {
	int n;

	cin >> n;
	
	long long ret = 1;
	for(int i=0; i<n; i++){
		ret *= 2;
	}
	cout << ret << endl;

	return 0;
}
