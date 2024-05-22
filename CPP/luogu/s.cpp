#include <bits/stdc++.h>
using namespace std;
long long n,m,q,ans[200005],dp[200005];
vector<long long>g[200005],qry[200005];
vector<pair<long long,long long> >mp[200005];
vector<long long>dstk;long long sum[200005<<2];
long long query(long long u, long long l, long long r, long long ql, long long qr) {
    if (ql <=l&&r<= qr)
        return sum[u];
    if (ql >r|| qr < l)
        return 1e18;
    long long ret = 0;
    long long mid = (l + r) / 2;
    ret = query(u * 2, l, mid, ql, qr);
    ret =min(ret, query(u * 2 + 1, mid + 1, r, ql, qr));
    return ret;
}
void update(long long u, long long l, long long r, long long pos, long long x) {
    if (l == r) {sum[u]=x;
        return;
    }
    long long mid = (l + r) / 2;
    if (pos <= mid)
        update(u * 2, l, mid, pos, x);
    else
        update(u * 2 + 1, mid + 1, r, pos, x);
    sum[u] = min(sum[2 * u] , sum[2 * u + 1]);
}
void dfs(long long u,long long f){
	if(u!=1)for(auto tmp:mp[u])dp[u]=min(dp[u],query(1,0,n,dstk.size()-tmp.first,dstk.size()-1)+tmp.second);
	for(long long id:qry[u])ans[id]=dp[u];
	update(1,0,n,dstk.size(),dp[u]);
	dstk.push_back(u);
	for(long long v:g[u])if(v!=f)dfs(v,u);
	dstk.pop_back();
	update(1,0,n,dstk.size(),1e18);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n>>m>>q;
	for(long long i=1;i<n;i++){
		long long u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}memset(sum,0x3f,sizeof(sum));
	for(long long i=1;i<=m;i++){
		long long x,k,v;
		cin>>x>>k>>v;
		mp[x].push_back({k,v});
	}
	for(long long i=1;i<=q;i++){
		long long id;
		cin>>id;
		qry[id].push_back(i);
	}
	memset(dp,0x3f,sizeof(dp));dp[1]=0;
	dfs(1,0);
	for(long long i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
}
