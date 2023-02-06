#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;

struct node{
	int to,next;
}e[maxn];

int cnt;
int nums = 0;
int head[maxn],vis[maxn];

void addnode(int u,int v){
	e[++cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void dfs(int x, int fa){
	vis[x] = 1;
	
	for(int i = head[x]; i; i=e[i].next){
		int y = e[i].to;
		
		if(y==fa) {
			continue;
		}	
		
		if(vis[y]==0){		
			dfs(y,x);
		} else if(vis[y]==1){
			nums++;	
		} else if(vis[y]==2){
			// 2 status means already cycle counted, so do count again
		}
	}

	vis[x] = 2;
}

int main()
{
	int n,m;
	int u,v;
	
	cin >> n >> m;
	
	for(int i = 1;i <= m;i++){
		cin >> u >> v;
		
		addnode(u,v);
		addnode(v,u);
	}

	for(int i = 1;i <= n;i++){
		if(vis[i]==0){
			dfs(i,-1);
		}
	}
	
	cout << nums << endl;
	
	return 0;
}


