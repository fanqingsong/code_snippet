#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int ans[1000006],fac[1000006];
int dp[2005];pair<int,int>num[2005];
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
}
int c(int a,int b){
	return (fac[a]*ans[b]%mod)*ans[a-b]%mod;
}
vector<int>t;
int jyh[1005];
int solve(int n,int m){
	if(n==0){
		return 0;
	}if(jyh[n]!=0){
		return jyh[n];
	}
	int ans=1;
	for(int i=0;i<m;i++){
		ans*=c(n-1+t[i],t[i]);
		ans%=mod;
	}
	return jyh[n]=(ans-n*solve(n-1,m)+mod)%mod;
}
signed main(){
	init();
	int h,w,n;
	cin>>h>>w>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i].first>>num[i].second;
	}
	num[0]=make_pair(1,1);
	num[n+1]=make_pair(h,w);
	sort(num,num+n+2);
	dp[0]=1;
	int sum=0;
	for(int i=1;i<=n+1;i++){
		dp[i]=c(num[i].first+num[i].second-2,num[i].first-1);
		for(int j=1;j<i;j++){
			if(num[i].first>=num[j].first&&num[i].second>=num[j].second)dp[i]=((dp[i]-dp[j]*c(
			num[i].first-num[j].first+num[i].second-num[j].second,num[i].first-num[j].first))%mod+mod)%mod;
		}
		if(i!=1&&i!=n+1){
			sum+=dp[i];
			sum%=mod;
		}
	}
	cout<<dp[n+1]<<endl;
}
