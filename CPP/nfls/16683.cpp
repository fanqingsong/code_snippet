#include <bits/stdc++.h>
using namespace std;
/*
Author yourdad
date -
status WATLERECEMLEOLEUKEJFPE
*/
struct edge{
	int w,t;
};
int ans;
vector<edge>v[40004];
bool vis[40004];
int lth[40004];
void dfs(int a){
	if(lth[a]){
		return;
	}
	vis[a]=1;
	int fst=0,sec=0;
	for(int i=0;i<v[a].size();i++){
		if(vis[v[a][i].t])continue;
		dfs(v[a][i].t);
		if(lth[v[a][i].t]+v[a][i].w>fst){
			sec=fst;
			fst=lth[v[a][i].t]+v[a][i].w;
		}else if(lth[v[a][i].t]+v[a][i].w>sec){
			sec=lth[v[a][i].t]+v[a][i].w;
		}
	}lth[a]=fst;
	ans=max(ans,fst+sec);
	return;
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
    	int a,b,c;
    	cin>>a>>b>>c;
    	char tmp;
    	cin>>tmp;
    	v[a].push_back({c,b});
    	v[b].push_back({c,a});
	}for(int i=1;i<=n;i++){
//		cout<<"666666666666"<<i<<endl;
		if(!vis[i]){
			dfs(i);
		}
	}cout<<ans<<endl;
}

