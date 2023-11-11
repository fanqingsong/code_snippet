#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll read(){
	ll f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	ll x=0;
	while(isdigit(c)){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return f*x;
}
ll hd[300005],tot,nxt[2000006],to[2000006],vl[2000006];
ll a[300005],dfn[300005],cnt,fa[300005][20],mn[300005];
ll stk[300005],dep[300005],top,dp[300005];
void add(ll u,ll v,ll w){
	tot++;
	to[tot]=v;
	vl[tot]=w;
	nxt[tot]=hd[u];
	hd[u]=tot;
	return ;
}
void ad(ll u,ll v){
	tot++;
	to[tot]=v;
	nxt[tot]=hd[u];
	hd[u]=tot;
	return ;
}
void mkdp(int u,int f){
	ll ans=0;
	dp[u]=mn[u];
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f){
			continue;
		}
		mkdp(v,u);
		ans+=dp[v];
	}
	hd[u]=0;
	if(ans!=0){
		dp[u]=ans;
	}
	return ;
}
ll lca(ll x,ll y){
	if(dep[y]<dep[x]){
		swap(x,y);
	}
	for(int i=19;i>=0;i--){
		if(dep[fa[y][i]]>=dep[x]){
			y=fa[y][i];
		}
	}
	if(y==x){
		return y;
	}
	for(int i=19;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
void dfs(ll u,ll f){
	dep[u]=dep[f]+1;
	cnt++;
	dfn[u]=cnt;
	fa[u][0]=f;
	for(int i=0;i<20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(ll i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f){
			continue;
		}
		mn[v]=min(mn[u],vl[i]);
		dfs(v,u);
	}
	return ;
}
bool cmp(int a,int b){
	return dfn[a]<dfn[b];
}
void add_edge(ll u,ll v,ll w){
	add(u,v,w);
	add(v,u,w);
}
void add_edg(ll u,ll v){
	ad(u,v);
	ad(v,u);
}
int main(){
	n=read();
	mn[1]=1e18;
	for(ll i=1;i<n;i++){
		ll u=read(),v=read(),w=read();
		add_edge(u,v,w);
	}
	dfs(1,0);
	for(int i=0;i<10;i++)cout<<mn[i+1]<<"==\n";
	int m=read();
	while(m--){
		ll k=read();
		for(int i=1;i<=k;i++){
			a[i]=read();
		}
		sort(a+1,a+1+k,cmp);
		tot=top=0;
		stk[++top]=1;
		hd[1]=0;
		for(int i=1;i<=k;i++){
			hd[a[i]]=0;
			int l=lca(a[i],stk[top]);
			if(dep[l]==dep[stk[top]]){
				stk[++top]=a[i];
				continue;
			}
			if(l!=stk[top]){
				while(dep[stk[top]]>dep[l]){
					add_edg(stk[top],stk[--top]);
				}
				if(stk[top]!=l){
					hd[l]=0;
					add_edg(stk[top],l);
				}
			}
			stk[++top]=a[i];
		}
		for(top=top-1;top;--top){
			add_edg(stk[top],stk[top+1]);
		}
		mkdp(1,0);

		for(int i=0;i<10;i++)cout<<dp[i+1]<<"==\n";
		cout<<dp[1]<<endl;
	}
}
