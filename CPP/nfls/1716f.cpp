#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e10+7;
int dp[3004][3004];
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		dp[0][i]=0;
	}for(int i=1;i<=n;i++){
		dp[i][0]=1;
	}for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(j<i){
				dp[i][j]=dp[i][j-1]+dp[i-1][j];
				dp[i][j]%=mod;
			}else{
				dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-i];
				dp[i][j]+=mod;
				dp[i][j]%=mod;
			}
		}
	}
	
	int ans=0;
	for(int i=0;i<=k;i++){
		ans+=dp[n][i];
		ans%=mod;
	}
	
	cout<<ans<<endl;
}
