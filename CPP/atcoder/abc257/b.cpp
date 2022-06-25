#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>

/*
https://atcoder.jp/contests/abc257/tasks/abc257_b
*/

int N, K, Q;

int a[202];

int main() {
	cin >> N >> K >> Q;
	
	for(int i=1; i<=K; i++){
		cin >> a[i];
	}

	for(int i=1; i <= Q; i++){
		int L;
		cin >> L;
		
		int pos_l = a[L];

		if (pos_l == N){
			continue;
		}

		int pos_l_next = a[L+1];
		if(pos_l + 1 == pos_l_next){
			continue;
		}
		
		a[L] ++;
	}
	
	for(int i=1; i<=K; i++){
		cout << a[i] << " ";
	}

	return 0;
}
