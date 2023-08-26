#include<bits/stdc++.h>
using namespace std;
long double dp[1000009];
signed main(){
	long long n,m;cin>>n>>m;for(int i=1;i<=m;i++)dp[i]=dp[i-1]+1.0/(1.0-(long double)(i-1)/(long double)n);
	cout<<fixed<<setprecision(7)<<dp[m]<<endl;
	return 0;
}
