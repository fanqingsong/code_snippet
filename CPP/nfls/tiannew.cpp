#include <bits/stdc++.h>
using namespace std;

bool vis[8][8];

struct node{
	int a[8][8],dp;
	node(){
		memset(a,0,sizeof(a));
		dp=0;
		// nothing
	}
	
	int calc()const{
		int ans=0;
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				if(a[i][j]!=0){
					ans++;
				}
			}
		}
		return ans;
	}
	
	bool n0(int n)const{
		for(int i=1;i<7;i++){
			if(a[i][n]!=0){
				return 1;
			}
		}
		return  0;
	}
};

bool operator < (node a, node b){return a.calc()<b.calc();}


int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

map<node,int>dp;

void ers(int h,int l,node &n){
	int lst=n.a[h][l];
	vis[h][l]=1;
	n.a[h][l]=0;
	for(int i=0;i<4;i++){
		if(n.a[h+dx[i]][l+dy[i]]==lst){
			ers(h+dx[i],l+dy[i],n);
		}
	}
}

void lg(node &ls){
	for(int i=1;i<7;i++){
		int l=1,r=1;
		while(l<7){
			if(ls.a[l][i]){
				ls.a[r][i]=ls.a[l][i],r++;
			}
			l++;
		}
		while(r<7){
			ls.a[r][i]=0;
			r++;
		}
	}
	int l=1,r=1;
	while(l<7){
		if(ls.n0(l)){
			for(int i=1;i<7;i++){
				ls.a[i][r]=ls.a[i][l];
			}
			r++;
		}
		l++;
	}
	while(r<7){
		for(int i=1;i<7;i++)ls.a[i][r]=0;
		r++;
	}
}/*
3 3
1 2 1
2 1 2
2 2 1
*/
node prs(int h,int l,node ls){
	ers(h,l,ls);
	lg(ls);
	return ls;
}
signed main(){
//	freopen("tian.in","r",stdin);
//	freopen("tian.out","w",stdout);
	int n,m;
	cin>>n>>m;
	node fst;
	for(int i=n;i;i--){
		for(int j=1;j<=m;j++){
			cin>>fst.a[i][j];
		}
	}
//	lg(fst);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<fst.a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	return 0;

	dp[fst]=0;
	
	queue<node>pq;
	pq.push(fst);
	
	while(!pq.empty()){
		node t=pq.front();
		pq.pop();
		bool ok=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(t.a[i][j])ok=0;
			}
		}
		if(ok){
			cout<<dp[t]<<endl;
			break;
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(t.a[i][j]==0||vis[i][j])continue;
				node lst=prs(i,j,t);
				if(dp[lst]==0)dp[lst]=dp[t]+1,pq.push(lst);
			}
		}
	}
}
