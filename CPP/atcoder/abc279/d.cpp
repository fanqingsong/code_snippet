#include <bits/stdc++.h>
using namespace std;

long long a, b;

long double get_t(long long x){
	long double ret = 0;
	ret = (long double)b*x + (long double)a/sqrt(x+1);
	
	return ret;
}

int main(){
	cout << fixed << setprecision(10);
	
	cin >> a >> b;
	
	long long l, r;
	l = 0;
	r = a;
	
	while(l < r){
//		cout << "---------------" << endl;
//		cout << "l = " << l << endl;
//		cout << "r = " << r << endl;
		
		long long len = r - l;
		long long one = len / 3;
		if (one == 0){
			break;
		} 
		
//		cout << "one = " << one << endl;
		
		long long mid1 = l + one;
		long long mid2 = r - one;
		
//		cout << "mid1 = " << mid1 << endl;
//		cout << "mid2 = " << mid2 << endl;
		
		if (mid1 >= mid2){
			break;
		}
		
		long double mid1v = get_t(mid1);
		long double mid2v = get_t(mid2);

//		cout << "mid1v = " << mid1v << endl;
//		cout << "mid2v = " << mid2v << endl;

		if(mid1v <= mid2v){
			r = mid2;
		} else if (mid1v > mid2v){
			l = mid1;
		} else {
			
		}
	}
	
	long long mini = l;
	long double minv = get_t(mini);
	for(long long i=l-10; i<=r+10; i++){
		long double cv = get_t(i);
		if(cv < minv){
			mini = i;
			minv = cv;
		}
	}

	cout << minv << endl;
}


