#include <bits/stdc++.h>
using namespace std;
long long ksm(long long a,long long x,long long m){
	long long ans=1ll;
	a%=m;
	for(;x;a*=a,a%=m){
		if(x&1){
			ans*=a;
			ans%=m;
		}
		x>>=1;
	}
	return ans;
}

long long solve(long long a, long long x, long long m){
	if(x==0){
		return 1ll;
	}
	
	if(!(x&1)){
		long long temp = 1ll + ksm(a,x/2ll,m)%m;
		temp %= m;
		
		long long temp2 = solve(a,(x/2ll)-1ll,m);
		temp2 %= m;
		
		return 1ll+(((a*temp)%m)*temp2)%m;
	}
	
	long long temp = ksm(a,x/2+1ll,m)%m;

	long long temp2 = solve(a,x/2ll,m)%m;
	
	return (((1ll+temp)%m)*temp2)%m;
}

int main(){
	long long a,x,m;
	
	cin>>a>>x>>m;
	
long long n=solve(a,x-1ll,m)%m;
cout<<n<<endl;
}
