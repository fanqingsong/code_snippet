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

bool check_base(int i, int base){
	while (i > 0){
		int q = i / base;
		int r = i % base;
		
		if (r == 0){
			return false;
		}
		
		i = q;
	}
	
	return true;
}

bool check(int i){
	if (!check_base(i, 5)){
		return false;
	}
	
	if (!check_base(i, 7)){
		return false;
	}

	if (!check_base(i, 9)){
		return false;
	}

	return true;
}


int main() {
	int a, b;
	cin >> a >> b;
	
	int count = 0;
	for(int i=a; i<=b; i++){
		if(!check(i)){
			continue;
		}
		
		count ++;
	}
	
	cout << count << endl;
	
	return 0;
}
