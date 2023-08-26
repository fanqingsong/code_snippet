#include <bits/stdc++.h>
using namespace std;
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long g = exgcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return g;
}
int main(){
	long long n,m=1;
	cin>>n;
	vector<long long>a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		m*=a[i];
	}
	long long y=0;
	long long l,lkl;
	for(int i=0;i<n;i++){
		l=0;long long g=exgcd(m/a[i],a[i],l,lkl);
		l*=m/a[i];
		y+=l*b[i];
	}
	cout<<((y%m)+m)%m<<endl;
}
