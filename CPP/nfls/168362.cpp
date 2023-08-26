#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[100005];
signed main(){
	int n,k;
	cin>>n>>k;
	deque<int>q;
	vector<int>v(n+1,0),sum(n+1,0);
	for(int i=1;i<=k;i++){
		cin>>v[i];
		dp[i]=sum[i]=sum[i-1]+v[i];if(i==1){
			continue;
		}
		int nm=dp[i-2]-sum[i-1];
		while(q.size()&&dp[q.back()-2]-sum[q.back()-1]<nm){
			q.pop_back();
		}q.push_back(i);
	}
	for(int i=k+1;i<=n;i++){
		int nm=dp[i-2]-sum[i-1];
		while(q.size()&&dp[q.back()-2]-sum[q.back()-1]<nm){
			q.pop_back();
		}q.push_back(i);cin>>v[i];sum[i]=sum[i-1]+v[i];
		while(q.size()&&q.front()<=i-k){
			q.pop_front();
		}
		dp[i]=dp[q.front()-2]+sum[i]-sum[q.front()-1];
		
	}cout<<dp[n]<<endl;
}
