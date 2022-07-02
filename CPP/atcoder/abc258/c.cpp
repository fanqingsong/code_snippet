#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>

/*
https://atcoder.jp/contests/abc258/tasks/abc258_c
*/

int n, q;
string s;
int head, tail;
int action, x;

int main() {
	cin >> n >> q;
	
	cin >> s;
	
	head = 0;

	for(int i=0; i<q; i++){
		cin >> action >> x;
		
		if (action == 1){
			head -= x;
			head += n;
			head %= n;
		} else if (action == 2){
			int index = (head + x -1) % n;
			cout << s[index] << endl;
		}
	}

	return 0;
}
