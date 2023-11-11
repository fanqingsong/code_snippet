#include <bits/stdc++.h>
using namespace std;
int deg[200005],ans[200005],bs[200005];
vector<int>zb[200005],e[200005];
inline int read(){
    int x = 0,f = 1, c = getchar();
    while(!isdigit(c)) f = (c == '-' ? -f : f), c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int main(){
	int n=read(),m=read(),q=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		e[u].emplace_back(v);
		e[v].emplace_back(u);
		deg[u]++,deg[v]++;
	}
	int s=ceil(sqrt(n));
	for(int i=1;i<=n;i++){
		for(int j:e[i]){
			if(deg[j]>=s)zb[i].emplace_back(j);
		}
	}
	while(q--){
		int tp=read();
		if(tp==1){
			int x=read(),w=read();
			bs[x]+=w;
			ans[x]=max(ans[x],bs[x]);
			if(deg[x]<s){
				for(int j:e[x]){
					ans[j]=max(ans[j],bs[x]);
				}
			}
		}else{
			int x=read();
			int res=ans[x];
			for(int j:zb[x])res=max(res,bs[j]);
			printf("%d\n",res);
		}
	}
}
