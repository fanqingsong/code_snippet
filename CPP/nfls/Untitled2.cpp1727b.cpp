#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int ans[1000006],fac[1000006],t[1000006];
signed init(){
	ans[1]=1;
	fac[1]=fac[0]=1;
	for(int i=2;i<=1000006;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	for(int i=2;i<=1000006;i++){
		ans[i]=((mod-(mod/i))*ans[mod%i])%mod;
	}for(int i=2;i<=1000006;i++){
		ans[i]*=ans[i-1];
		ans[i]%=mod;
	}
	return 0;
}
int c(int a,int b){
	return (((fac[a]*ans[b])%mod)*ans[a-b])%mod;
}
int solve(int n,int m){
	if(n==0){
		return 0;
	}
	int anns=1;
	for(int i=0;i<m;i++){
		anns*=c(n-1+t[i],n-1);
		anns%=mod;
	}
	return anns%mod;
}
signed main(){
	init();
	cout << "after init\n";
	int n,m,ans=1;
	cin>>n>>m;
	cout << "after n m\n";
	for(int i=0;i<m;i++){
		cout << "after i=" <<i<<"\n";
		cin>>t[i];
	}
	cout << "after t\n";
	int rans=0;
	for(int i=0;i<n;i++){
		if(i&1)rans-=c(n,i)*solve(n-i,m);
		else rans+=c(n,i)*solve(n-i,m);
		rans=(rans%mod+mod)%mod;
	}
	cout<<mod-rans<<endl;
}
