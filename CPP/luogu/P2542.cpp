#include <bits/stdc++.h>
using namespace std;
int tot,hd[200006],nxt[1000006],to[1000006];
bool cn[1000006];
struct qst{
	int tp,a,b,res;
}qs[500005];
int n,m,q;
map<int,int>idx;
void add(int u,int v){
	tot++;
	nxt[tot]=hd[u];
	to[tot]=v;
	hd[u]=tot;
	idx[u*(n+1)+v]=tot;
	cn[tot]=0;
}
int sz[200005],dep[200005],son[200005],fa[200005];
void dfs1(int u,int f){
	sz[u]=1;
	dep[u]=dep[f]+1;
	fa[u]=f;
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(sz[v]||cn[i]){
			continue;
		}
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]){
			son[u]=v;
		}
	}
	return  ;
}
int top[200005],dfn[200005],cnt;
void dfs2(int u,int f){
	dfn[u]=++cnt;
	if(u==son[f]){
		top[u]=top[f];
	}else{
		top[u]=u;
	}
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(fa[v]!=u||cn[i]){
			continue;
		}
		dfs2(v,u);
	}
	return  ;
}

int sum[800006],lzy[800006];
void build(int u,int l,int r){
	lzy[u]=0;
	if(l==r){sum[u]=1;return ;}
	int mid=(l+r)/2;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	sum[u]=sum[u*2]+sum[u*2+1];
}
void putlazy(int u){
	sum[u]=0;
	lzy[u]=1;
}
void push_down(int u){
	if(lzy[u]==0)return ;
	lzy[u]=0;
	putlazy(u*2);
	putlazy(u*2+1);
	return ;
}
void update(int u,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr){
		putlazy(u);
		return ;
	}
	push_down(u);
	int mid=(l+r)/2;
	if(ql<=mid)update(u*2,l,mid,ql,qr);
	if(qr>mid)update(u*2+1,mid+1,r,ql,qr);
	sum[u]=sum[u*2+1]+sum[u*2];
}
int query(int u,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr){
		return sum[u];
	}
	push_down(u);int mid=(l+r)/2,ans=0;
	if(ql<=mid)ans+=query(u*2,l,mid,ql,qr);
	if(qr>mid)ans+=query(u*2+1,mid+1,r,ql,qr);
	return ans;
}
void cg(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		update(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y])
		swap(x,y);
	if(dep[x]!=dep[y])
		update(1,1,n,dfn[y]+1,dfn[x]);
}
void dfs3(int u,int f){
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i];
		if(f==v||cn[i]){
			continue;
		}
		if(fa[v]==u){
			dfs3(v,u);
		}
		if(dep[v]<dep[u])cg(v,u);
	}
	return  ;
}
int ak(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]){
			swap(x,y);
		}
		ans+=query(1,1,n,dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	ans+=query(1,1,n,dfn[y],dfn[x]);
	ans-=query(1,1,n,dfn[y],dfn[y]);
	return ans;
}
int main(){
	freopen("lane.in","r",stdin);
	freopen("lane.out","w",stdout);
	cin>>n>>m>>q;
	while(m--){
		int u,v;
		cin>>u>>v;
		add(u,v);add(v,u);
	}
	for(int i=0;i<q;i++){
		cin>>qs[i].tp>>qs[i].a>>qs[i].b;
		if(qs[i].tp==0){
			cn[idx[qs[i].a*(n+1)+qs[i].b]]=1;
			cn[idx[qs[i].b*(n+1)+qs[i].a]]=1;
		}
	}
	dfs1(1,0);
	dfs2(1,0);
	build(1,1,n);
	dfs3(1,0);
//	for(int i=1;i<=n;i++){
//		cout<<top[i]<<"=="<<dfn[i]<<endl;;
//	}
//	cout<<endl;
	for(int i=q-1;i>=0;i--){
		if(qs[i].tp==0){
			cg(qs[i].a,qs[i].b);
		}else{
			qs[i].res=ak(qs[i].a,qs[i].b);
		}
	}
	for(int i=0;i<q;i++){
		if(qs[i].tp==1){
			cout<<qs[i].res<<endl;
		}
	}
}
