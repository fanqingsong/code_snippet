#include <bits/stdc++.h>
using namespace std;
long long dp[20005],qzh[20005];
const long long mod=1e9+7;
long long main(){
	string s;
	cin>>s;
	long long n=s.size();
	s=' '+s;
	for(long long i=0;i<=n;i++){
		qzh[i]=1;
	}
	for(long long i=1;i<=n;i++){
		if(s[i]!='.')memset(dp,0,sizeof(dp));
		if(s[i]=='L'){
			for(long long j=i;j;j--){
				(dp[j]+=qzh[j-1])%=mod;
			}
		}if(s[i]=='R'){
			for(long long j=i;j<=n;j++){
				(dp[j]+=qzh[j-1])%=mod;
			}
		}
		if(s[i]!='.'){qzh[0]=0;
			for(long long j=1;j<=n;j++){
				qzh[j]=(qzh[j-1]+dp[j])%mod;
			}
		}
	}cout<<qzh[n];
}
