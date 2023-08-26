#include <bits/stdc++.h>
using namespace std;
/*
Author fanchuanyu
date -
status WATLERECEMLEOLEUKEJFPE
*/
#define int long long
const int mod=998244353;
int n,a[400005],ct[400005],nta[400005],als[400005];
int fa[400005],ls[400005],rs[400005],cnt;
int ksm(int k,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans*=k;
			ans%=mod;
		}
		k*=k;
		k%=mod;
		b>>=1;
	}
	return ans;
}int inv(int k){
	return ksm(k,mod-2);
}void dfs(int x,int t){
	if(x<=n){a[x]=t;return;}
	dfs(ls[x],(t+1ll*ct[ls[x]]*inv(ct[x])%mod)%mod);
	dfs(rs[x],(t+1ll*ct[rs[x]]*inv(ct[x])%mod)%mod);
}
int find(int n){
	if(fa[n]==-1){
		return n;
	}
	return fa[n]=find(fa[n]);
}
signed main(){
	memset(fa,-1,sizeof(fa));
	cin>>n;
	for(int i=1;i<=n;i++){
		ct[i]=1;
	}
	cnt=n;
	for(int i=1;i<n;i++){
		int p,q;
		cin>>p>>q;p=find(p),q=find(q);
		fa[p]=fa[q]=n+i;ct[n+i]=ct[p]+ct[q];
		ls[n+i]=p;rs[n+i]=q;
//		cout<<a[p]<<" "<<a[q]<<endl;
	}dfs(n*2-1,0);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}cout<<endl;
}

