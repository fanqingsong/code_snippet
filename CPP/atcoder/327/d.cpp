#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;
int n,m,color[200010], a[200010], b[200010];
vector<int> edge[200010];


int dfs(int x,int c){
	color[x]=c

;
	for(int i=0;i<edge[x].size();i++){
		int v=edge[x][i];
		if(color[v]==color[x]){
			return 0;
		}
		if(color[v]==0 && !dfs(v,-c)){
			return 0;
		}
	}
	return 1;
}
void solve(){
	for(int i=1;i<=n;i++){
		if(color[i]==0){
			if(!dfs(i,1)){
				printf("No");
				return ;
			}
		}
	}
	printf("Yes");
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	
	for(int i=1;i<=m;i++){
		cin >> b[i];
	}

	for(int i=1;i<=m;i++){
		int x,y;
		x = a[i];
		y = b[i];
//		scanf("%d%d",&x,&y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	solve();
	return 0;
}
