#include <bits/stdc++.h>
using namespace std;
int main(){
	int dp[100005];
	int n,k;
	cin>>n>>k;
	deque<int>q;
	vector<int>v(n+1,0),sum(n+1,0);
	for(int i=1;i<=k;i++){
		cin>>v[i];
		dp[i]=sum[i]=sum[i-1]+v[i];
		int nm=dp[i]-sum[i-1];
		while(q.size()&&dp[q.back()-1]-sum[q.back()]<nm){
			q.pop_back();
		}q.push_back(i);
	}
	for(int i=k+1;i<=n;i++){
		cin>>v[i];sum[i]=sum[i-1]+v[i];
		while(q.size()&&q.front()<i-k){
			q.pop_front();
		}
		dp[i]=dp[q.front()-1]+sum[i]-sum[q.front()];
		int nm=dp[i-1]-sum[i];
		while(q.size()&&dp[q.back()-1]-sum[q.back()]<nm){
			q.pop_back();
		}q.push_back(i);
	}cout<<dp[n]<<endl;
}
