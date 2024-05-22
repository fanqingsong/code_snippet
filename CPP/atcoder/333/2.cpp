#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],h[200005],p[200005],mn,mx;
void mk(int p1,int p2){//p1>p2
	if(a[p1]==a[p2]){
		if(h[p1]>h[p2])return ;
		else mn=1e18,mx=-1e18;
	}else if(a[p1]>a[p2]){
		if(h[p1]>h[p2])return ;
		else mn=max(mn,(h[p2]-h[p1])/(a[p1]-a[p2])+1);
	}else{
		if(h[p1]<h[p2])mn=1e18,mx=-1e18;
		else mx=min(mx,(h[p1]-h[p2]-1)/(a[p2]-a[p1]));
	}
	return ;
}
void solve(){
	int n;
	cin>>n;
	memset(a,0,sizeof(a));
	memset(h,0,sizeof(h));
	mn=0,mx=1e18;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){int k;cin>>k;p[k+1]=i;}
	for(int i=1;i<n;i++){
 		mk(p[i],p[i+1]);
	}
	if(mn>mx)cout<<"-1"<<"\n";
	else cout<<mn<<"\n";
	return ;
}
signed main(){
	int T;
	cin>>T;
	while(T--)solve();
}
