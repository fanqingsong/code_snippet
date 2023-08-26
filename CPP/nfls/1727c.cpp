#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int ans[1000006],fac[1000006];
signed init(){
	ans[1]=ans[0]=1;
	fac[1]=1;
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
}int c(int a,int b){
	return (fac[a]*ans[b]%mod)*ans[a-b]%mod;
}
map<int,int>cnt;
map<int,int>::iterator itr;
signed main(){
	init();
	int h,w,n;
	cin>>h>>w>>n;
	
}
