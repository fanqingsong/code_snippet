#include <bits/stdc++.h>
using namespace std;
char c[305][305];
int cnt=0;
bool vis[305][305][4];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void dfs(int x,int y,int dr){
	vis[x][y][dr]=1;
	if(c[x+dx[dr]][y+dy[dr]]=='.'){
		dfs(x+dx[dr],y+dy[dr],dr);
	}else{
		for(int k=0;k<4;k++){
			if(!vis[x][y][k]){
				dfs(x,y,k);
			}
		}
	}
	return;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>c[i][j];
		}
	}
	dfs(1,1,3);
	int ans=0;
	for(int i=1;i<n-1;i++){
		for(int j=1;j<m-1;j++){
			if(vis[i][j][0]||vis[i][j][1]||vis[i][j][2]||vis[i][j][3]){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
