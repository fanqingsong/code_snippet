

#include <bits/stdc++.h>
using namespace std;
#define int long long
int w[1005];
struct edge{
	int u,v,w;
	friend bool operator<(edge a,edge b){
		return a.w<b.w;
	}
};
int sz[5005],fa[5005];
int ff(int u){
	return fa[u]==u?u:fa[u]=ff(fa[u]);
}
signed main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	if(n*w[1]>=k){
		cout<<0<<endl;
		return 0;
	}
	int res=LLONG_MAX;
	vector<edge>v(m);
	
	for(int i=0;i<m;i++)cin>>v[i].u>>v[i].v>>v[i].w;
	sort(v.begin(),v.end());
	
	for(int i=0;i<m;i++){
		if(i&&v[i].w==v[i-1].w){
			continue;
		}
		
		for(int i=1;i<=n;i++)sz[i]=1,fa[i]=i;
		
		int ans=n*w[1], pos=i-1;
		
		while(ans<k&&pos+1<m){
			pos++;
			int r=pos-1;
			while(r<m-1&&v[r+1].w==v[pos].w){
				r++;
				int a=ff(v[r].u),b=ff(v[r].v);
				if(ff(v[r].u)!=ff(v[r].v)){
					ans-=w[sz[a]]+w[sz[b]];
					sz[b]+=sz[a];
					sz[a]=0;
					ans+=w[sz[b]];
					fa[a]=b;
				}
			}
			pos=r;
		}
		
		if(ans>=k)res=min(res,v[pos].w-v[i].w);
	}
	
	if(res==LLONG_MAX)cout<<"T_T";
	else cout<<res<<'\n';
}
/*
things to check
0.delete cerr code or use '//'
1.initallize(especially multicases)
2.int overflow/long long mle
3.if make the ans is hard , try 2-divided
4.memory &b-&a
5.function canshu position
6.the format of input
7.size enough ?
8.the name of function
9.stop copying x0->y0
*/

