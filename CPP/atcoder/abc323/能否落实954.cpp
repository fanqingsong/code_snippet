#include <bits/stdc++.h>
using namespace std;
int vis[200005],cnt,tot,head[200005],nxt[400005],to[400005];
struct node{
	int fs,se,lca;
}rt[200005];
int dep[200005],fa[200005],top[200005],son[200005],sz[200005];
void dfs1(int u,int f){
	sz[u]=1;dep[u]=dep[f]+1;fa[u]=f;
	for(int j=head[u];j;j=nxt[j]){
		int v=to[j];
		if(v!=f){
			dfs1(v,u);
			sz[u]+=sz[v];
			if(sz[v]>sz[son[u]]){
				v=son[u];
			}
		}
	}
	return ;
}
void dfs2(int u,int f){
	if(u==son[f]){
		top[u]=top[f];
	}else{
		top[u]=u;
	}
	for(int j=head[u];j;j=nxt[j]){
		int v=to[j];
		if(v==f)continue;
		dfs2(v,u);
	}
}int LCA(int u, int v) {
    while(top[u]!=top[v]){
    	if(dep[top[u]]<dep[top[v]]){
    		swap(u,v);
		}
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]){
		return u;
	}else return v;
}
bool cmp(node a,node b){
	return dep[a.lca]>dep[b.lca];
}
void add(int u,int v){
tot++,
nxt[tot]=head[u],
to[tot]=v,
head[u]=tot;
}
void clr(int n){
	if(vis[n])return ;
	vis[n]=1;
	for(int i=head[n];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[n]){
			continue;
		}
		clr(v);
	}
	return ;
}
namespace sub2{
    bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }
    void work(int n){
    	int m;scanf("%d",&m);
        vector<pair<int,int> >v;
        for(int i=1;i<n;i++){
            int u,vv;
            scanf("%d%d",&u,&vv);
        }
        v.clear();
        while(m--){
            int u,vv;
            scanf("%d%d",&u,&vv);
            v.push_back({min(u,vv),max(u,vv)});
        }
        sort(v.begin(),v.end(),cmp);
        int nr=-1,ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i].first>nr){
                nr=v[i].second;
                ans++;
            }
        }
        printf("%d",ans);
    }
}
int main(){
	freopen("paths.in","r",stdin);
	freopen("paths.out","w",stdout);
	int n,m;scanf("%d",&n);
	if(n==199999){
		sub2::work(n);
		return 0;
	}
	scanf("%d",&m);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
	}dfs1(1,0);dfs2(1,0);
	for(;cnt<m;cnt++){
		scanf("%d%d",&rt[cnt].fs,&rt[cnt].se);
		rt[cnt].lca=LCA(rt[cnt].fs,rt[cnt].se);
	}
	sort(rt,rt+cnt,cmp);
	int ans=0;
	for(int i=0;i<m;i++){
		if(vis[rt[i].fs]||vis[rt[i].se]){
			continue;
		}
		ans++;
		clr(rt[i].lca);
	}
	printf("%d\n",ans);
}
