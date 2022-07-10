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
https://atcoder.jp/contests/abc259/tasks/abc259_c
*/


int main() {
	string s, t;
	
	cin >> s;
	cin >> t;
	
	int sl = s.size();
	int tl = t.size();

	int si=0, ti=0;

	while(true){
		char sa = s[si];
		int sc = 0;
		while(si<sl){
			if(s[si] == sa){
				sc++;
				si++;
			} else {
				break;
			}
		}

		char ta = t[ti];
		int tc = 0;
		while(ti<tl){
			if(t[ti] == ta){
				tc++;
				ti++;
			} else {
				break;
			}
		}

		if (sa != ta){
			cout << "No" <<endl;
			return 0;
		}else {
			if (sc == 1){
				if ( tc > 1 ){
					cout << "No" <<endl;
					return 0;
				}
			} else {
				if(sc > tc){
					cout << "No" <<endl;
					return 0;
				}
			}
		}
		
		if (si>=sl && ti>=tl){
			break;
		}
	}
	
	cout << "Yes" << endl;
	
	return 0;
}
