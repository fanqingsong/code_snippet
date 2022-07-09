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
https://codeforces.com/problemset/problem/5/a
*/

int main() {
	string input;
	
	int pcount = 0;
	int tcount = 0;

	while(getline(cin, input)){
//		cout << "input = " << input << endl;
		char first = input[0];
		
		if(first == '+'){
			//
			pcount ++;
		} else if (first == '-'){
			//
			pcount --;
		} else {
			//
			int index = input.find(":");
			int mlen = input.size() - 1 - index;
			tcount += mlen * pcount;
		}
	}
	
	cout << tcount << endl;
	
	return 0;
}
