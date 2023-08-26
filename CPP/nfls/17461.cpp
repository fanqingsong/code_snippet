#include <bits/stdc++.h>
using namespace std;
/*
Author fanchuanyu
date 8.9
status WA+TLE+RE+CE+MLE+OLE+UKE+JF+PE+FE
*/
int n,k,match[40005];bool is[40005][40005],mark[505];
bool sp(int x){
	for(int i=1;i<=n;i++){
		if(!is[x][i]||mark[i]){
			continue;
		}mark[i]=1;
		if(match[i]==-1||sp(match[i])){
			match[i]=x;
			return 1;
		}
	}
	return 0;
}
int main(){
	memset(match,-1,sizeof(match));
    scanf("%d%d",&n,&k);
	while(k--){
		int x,y;
		scanf("%d%d",&x,&y);
		is[x][y]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(mark,0,sizeof(mark));
		if(sp(i)){
			ans++;
		}
	}
	cout<<ans<<endl;
}
