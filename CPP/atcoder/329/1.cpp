#include<bits/stdc++.h>
using namespace std;
int bel[100005];
bool ok[200005];
vector<int>g[200005];
bool vis[200005];
int fa[200005];
int ff(int n){return fa[n]==n?n:fa[n]=ff(fa[n]);}
void solve(){
	memset(vis,0,sizeof(vis));
	memset(ok,0,sizeof(ok));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*2+4;i++)fa[i]=i;
	for(int i=1;i<=n;i++){
		bel[i]=i*2;
		g[i].clear();
	}
	while(m--){
		char c;
		cin>>c;
		if(c=='U'){
			int u;cin>>u;
			bel[u]=0;
		}else if(c=='T'||c=='F'){
			int u;
			cin>>u;
			bel[u]=n*2+2;
		}else if(c=='+'){
			int u,v;
			cin>>u>>v;
			bel[u]=bel[v];
		}else if(c=='-'){
			int u,v;
			cin>>u>>v;
			bel[u]=bel[v]^1;
		}
	}
	ok[0]=1;
	int ans=0;
	queue<int>q;
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++){
		fa[ff(i*2)]=ff(bel[i]);
		fa[ff(i*2+1)]=ff(bel[i]^1);
	}
	for(int u=1;u<=n;u++){
		if(ff(u*2)==ff(u*2+1)||bel[u]==0||bel[u]==1){
			q.push(u);
			vis[u]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(bel[i]>=2)g[bel[i]/2].push_back(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		ans++;
		for(int v:g[u])if(!vis[v])q.push(v),vis[v]=1;
	}
	cout<<ans<<endl;
}
int main(){
	int c,t;
	cin>>c>>t;
	while(t--)solve();
}
