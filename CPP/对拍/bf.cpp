#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],dp[100005];
string s;
const int mod=1e9+7;
int dfs(int l,bool lim){
	if(l==s.size()-1){
		return 1;
	}if(!lim&&dp[l]!=-1){
		return dp[l];
	}int res=0;
	if(!lim){
		res+=3*dfs(l+1,0);
		res%=mod;
	}
	else if(s[l+1]=='1'){
		res+=2*dfs(l+1,lim);
		res%=mod;
		res+=dfs(l+1,0);
		res%=mod;
	}else{
		res+=dfs(l+1,lim);
		res%=mod;
	}
	if(!lim){
		dp[l]=res;
	}
	return res;
}signed main(){
	memset(dp,-1,sizeof(dp));
	cin>>s;
	cout<<dfs(-1,1)<<endl;
}
