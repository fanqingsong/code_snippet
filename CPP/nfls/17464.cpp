#include <bits/stdc++.h>
using namespace std;
/*
Author fanchuanyu
date -
status WATLERECEMLEOLEUKEJFPE
*/
int tot,s[200000],dy[8]={1,-1,1,-1,2,-2,2,-2},dx[8]={2,2,-2,-2,1,1,-1,-1};
vector<int>ed[200000];
int match[200000],vis[200000];
char c[205][205];
bool sp(int x,int tag){
	if(vis[x]==tag)return false;
	vis[x]=tag;
	for(int i=0;i<ed[x].size();i++){
		if(match[ed[x][i]]==-1||sp(match[ed[x][i]],tag)){
			match[ed[x][i]]=x;
			return 1;
		}
	}
	return 0;
}
int main(){
	memset(vis,0,sizeof(vis));
	memset(match,-1,sizeof(match));
    int n,m=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",c[i]+1);
	}
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
			if(c[i][j]=='0'&&(i+j)&1){
	    		s[++tot]=i*(n+1)+j;
    			for(int l=0;l<8;l++){
    				int nx=i+dx[l],ny=j+dy[l];
    				if(nx<=0||nx>n||ny<=0||ny>n&&c[nx][ny]=='0'){
    					continue;
					}
					ed[s[tot]].push_back(nx*(n+1)+ny);
				}
			}else if(c[i][j]=='1'){
				m++;
			}
		}
	}
	int ans=0;
	for(int k=1;k<=tot;k++){
		if(sp(s[k],k)){
			ans++;
		}
	}
	cout<<(n*n-m-ans)<<endl;
}

