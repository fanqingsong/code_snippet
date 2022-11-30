#include <bits/stdc++.h>
using namespace std;
long long a,b;

long double f(long long x){
	return (long double)b*x+(long double)a/sqrt(x+1);
}
int main(){

	cin>>a>>b;
	if(b>=a){
		cout<<fixed<<setprecision(7)<<a;

		return 0;
	}
	long long l=0,r=a;
	while(l<r){
		long long mid=(l+r)/2;
//		cout << "mid = " << mid << endl;
//		cout << "mid-1 v = "<<fixed<<setprecision(14) << f(mid-1) << endl;
//		cout << "mid = "<<fixed<<setprecision(14) << f(mid) << endl;
//		cout << "mid+1 v = "<<fixed<<setprecision(14) << f(mid+1) << endl;
		if(f(mid-1)>=f(mid)&&f(mid)<=f(mid+1)){
			cout<<fixed<<setprecision(7)<<f(mid)<<endl;
			return 0;
		}
		else if(f(mid)>f(mid-1)){
			r=mid;
		}
		else{
			l=mid;
		}
	}
	return 0;
}
