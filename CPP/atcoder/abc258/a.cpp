#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>

/*
https://atcoder.jp/contests/abc258/tasks/abc258_a
*/

int main() {

	int k;
	
	cin >> k;
	
	int hours = k / 60;
	int minutes = k % 60;
	
	int hh = 21 + hours;
	int mm = minutes;
	string smm;
	if (mm < 10){
		smm.append("0");
	}
	smm.append(to_string(mm));
	
	cout << hh << ":" << smm << endl;

	return 0;
}
