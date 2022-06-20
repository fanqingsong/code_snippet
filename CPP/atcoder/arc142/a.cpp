#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

/*
https://atcoder.jp/contests/arc142/tasks/arc142_a
*/

long long search(long long n, long long k){
	if (n < k){
		return 0;
	}
	
	string kstr = to_string(k);
	
	reverse(kstr.begin(), kstr.end());
	
	long long k_r = stoll(kstr);
	
	if(k_r < k){
		return 0;
	}
	
//	cout << "k = " << k << endl;
//	cout << "k_r =" << k_r << endl;
	
	long long counter = 0;
	
	if(k_r == k){
		while(k <= n){
			counter ++;
			
			k *= 10;
		}
		
		return counter;
	}
	
	while(k <= n){
		counter++;
		
		k *= 10;
	}
	
	while(k_r <= n){
		counter++;
		
		k_r *= 10;
	}
	
	return counter;
}

int main() {
	long long n, k;
	
	cin >> n >> k;
	
	long long ans = search(n, k);
	
	cout << ans << endl;
	
	return 0;
}
