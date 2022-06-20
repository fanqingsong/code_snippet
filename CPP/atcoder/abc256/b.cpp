#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>

/*
https://atcoder.jp/contests/abc256/tasks/abc256_b
*/

vector<int> sq;

int main() {
	int n;

	cin >> n;
	
	int p = 0;
	
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		
		sq.push_back(0);

		vector<int>::iterator it;
		for(it=sq.begin(); it!=sq.end(); it++){
			*it += a;			
		}
	}

	vector<int>::iterator it;
	for(it=sq.begin(); it!=sq.end(); it++){
		if(*it >= 4){
			p++;
		}
	}

	cout << p << endl;

	return 0;
}
