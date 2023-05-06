#include <bits/stdc++.h>
using namespace std;

int main(){
	int x, y, t;
	
	cin >> x >> y >> t;
	
	int pre = 11 * 7;
	
	int vdiff = 10; //21 - 11;
	
	double tleft = (double)pre / vdiff;

	double tt = pre + tleft * x;
	double rr = tleft * y;
	
	cout << tt << " " << rr << endl;
}
