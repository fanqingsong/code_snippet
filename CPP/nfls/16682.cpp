#include <bits/stdc++.h>
using namespace std;
int fa[305],pnt[305],dp[305][305],head[305]={0},tot,nxt[305]={0},to[305],n,m;
void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return;
}
void dfs(int a){
	dp[a][1]=pnt[a];
	for(int i=head[a];i;i=nxt[i]){
		dfs(to[i]);
		for(int j=m;j>=0;j--){
			for(int k=0;k<j;k++){
				dp[a][j]=max(dp[a][j],dp[to[i]][k]+dp[a][j-k]);
			}
		}
	}
	return;
}
int main(){
	memset(dp,0,sizeof(dp));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>fa[i]>>pnt[i];
		add(fa[i],i);
	}
	m++;
	dfs(0);
	cout<<dp[0][m]<<endl;
}
