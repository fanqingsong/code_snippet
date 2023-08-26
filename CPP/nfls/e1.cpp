#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,dp[105][10005],tr[10005],a[10005];
int lowbit(int x){
	return x&(-x);
}void add(int t,int num){
	if(t>n){
		return;
	}
	tr[t]+=num;
	tr[t]%=20140921;
	add(t+lowbit(t),num);
}
void clr(){
	memset(tr,0,sizeof(tr));
}int sum(int n){
	if(n==0)return n;
	return (sum(n-lowbit(n))+tr[n])%20140921;
}
signed main(){
	cin>>n>>m;
	vector<int>v;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
	}for(int i=0;i<=n;i++){
		dp[1][i]=1;
	}for(int j=2;j<=m;j++){
		clr();
		for(int i=1;i<=n;i++){
			dp[j][i]=sum(a[i]-1)%20140921;
			add(a[i],dp[j-1][i]);
		}
	}int sum=0;
	for(int i=1;i<=n;i++){
		sum+=dp[m][i];
//		cout<<dp[m][i]<<endl;
		sum%=20140921;
	}
	cout<<sum<<endl;
}
