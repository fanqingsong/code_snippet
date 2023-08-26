#include <bits/stdc++.h>
const int N=1e5+5;
using namespace std;
int n,m,u,tot,top,cnt,c1,c2,in[N],stk[N],v,out[N],dfn[N],low[N],instk[N],belong[N];
vector<int>son[N];
void dfs(int x) {
	dfn[x]=low[x]=++tot;
	stk[++top]=x;
	instk[x]=true;
	for(int i=0; i<son[x].size(); i++) {
		int y=son[x][i];
		if(dfn[y]==0) {
			dfs(y);
			low[x]=min(low[x],low[y]);
		} else if(instk[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]) {
		cnt++;
		int y;
		do {
			y=stk[top--];
			instk[y]=false;
			belong[y]=cnt;
		} while(y!=x);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		son[u].push_back(v);
	}for(int i=1;i<=n;i++){
		if(!dfn[i]){
			dfs(i);
		}
	}for(int i=1;i<=n;i++){
		for(int j=0;j<son[i].size();j++){
			if(belong[i]!=belong[son[i][j]]){
				out[belong[i]]++;
				in[belong[son[i][j]]]++;
			}
		}
	}for(int i=1;i<=cnt;i++){
		if(!in[i]){
			c1++;
		}if(!out[i]){
			c2++;
		}
	}cout<<max(c1,c2)<<endl;
}
