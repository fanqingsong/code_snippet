#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>

/*
https://atcoder.jp/contests/abc258/tasks/abc258_d
*/

int n, x;
int a[200005];
int b[200005];


int main() {
	cin >> n >> x;
	
	for(int i=1; i<=n; i++){
		cin >> a[i] >> b[i];
	}

	long long base=0, supplement=0, cost=-1;
	
	for(int i=1; i<=n; i++){
		if (i > x){
			break;
		}
		
		base += a[i] + b[i];
		supplement = (long long)b[i] * (x - i);
		
		if(cost == -1) {
			cost = base + supplement;
		} else {
			cost = min(cost, base + supplement);
		}
	}
	
	cout << cost << endl;

	return 0;
}
