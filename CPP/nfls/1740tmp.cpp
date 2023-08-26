#include<bits/stdc++.h>
#define LIM 100005
using namespace std;
int n,m,u,v,tot,stk[LIM],top,cnt;
int dfn[LIM],low[LIM],link[LIM];
int in[LIM],out[LIM],I,O;
vector<int>edge[LIM];
void dfs(int now){
	low[now]=dfn[now]=++tot;
	stk[++top]=now;
	for(int i=0;i<edge[now].size();i++){
		int nxt=edge[now][i];
		if(!dfn[nxt]){
			dfs(nxt);
			low[now ]=min(low[now],low[nxt]);
		}
		else if(!link[nxt]){
			low[now]=min(low[now],dfn[nxt]);
		}
	}
	if(low[now]==dfn[now]){
		link[now]=++cnt;
		while(now!=stk[top])link[stk[top--]]=cnt;
		top--;
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i <=m;i++){
		scanf("%d %d",&u,&v);
		edge[u].push_back(v);
	}for (int i=1;i <=n;i++)
		if (!dfn[i])
			dfs(i);
	for (int i=1;i <=n;i++){
		for (int j=0;j<edge[i].size();j++){
			int nxt=edge[i][j];
			if (link[i]!=link[nxt])
				out[link[i]]++,in[link[nxt]]++;
		}
	}
	for (int i=1;i <=cnt;i++){
		if (!in[i])
			I++;
		if (!out[i])
			O++;
	}
	printf("%d",max(I,O));
	return 0;
}


