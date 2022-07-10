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
https://atcoder.jp/contests/abc259/tasks/abc259_b
*/

//#define PI 3.14159265358979323846
const double PI=acos(-1);


int main() {
	int a, b, d;

	cin >> a >> b >> d;

	if (a==0 && b==0){
		cout << "0" << " " << "0" << endl;
		return 0;
	}

	long double banjing = sqrt(pow(a,2) + pow(b, 2));

	long double cos_val = (long double) a / banjing;

	long double radian = 0;

	if (a==0 && b>0){
		radian = PI / 2;
	} else if (a==0 && b<0){
		radian = PI * 3 / 2;
	} else if (a>0 && b==0){
		radian = 0;
	} else if (a<0 && b==0){
		radian = PI;
	} else if (a>0 && b>0){
		radian = acos(cos_val);
	} else if (a<0 && b>0) {
		cos_val = -cos_val;
		radian = acos(cos_val);
		radian = PI - radian;
	} else if (a<0 && b<0){
		cos_val = -cos_val;
		radian = acos(cos_val);
		radian = PI + radian;
	} else if (a>0 && b<0){
		radian = acos(cos_val);
		radian = 2 * PI - radian;
	}

	long double new_radian = radian + 2*PI * (long double) d / 360;

	long double new_a = banjing * cos(new_radian);
	long double new_b = banjing * sin(new_radian);

	cout << setprecision(15) << new_a << " " << setprecision(15) << new_b << endl;

	return 0;
}
