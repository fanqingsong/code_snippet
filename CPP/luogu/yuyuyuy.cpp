#include <bits/stdc++.h>
using namespace std;
long long a[200005];
vector<long long>gbs[200005<<2],qzh[200005<<2];
void build(long long u,long long l,long long r){
	if(l==r){
		gbs[u].push_back(a[l]);
		qzh[u].push_back(a[l]);
		return ;
	}
	long long mid=l+r>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	gbs[u].resize(r-l+1);
	qzh[u].resize(r-l+1);
	merge(gbs[u<<1].begin(),gbs[u<<1].end(),gbs[u<<1|1].begin(),gbs[u<<1|1].end(),gbs[u].begin());
	qzh[u][0]=gbs[u][0];
	for(int i=1;i<gbs[u].size();i++){
		qzh[u][i]=qzh[u][i-1]+gbs[u][i];
	}
}
long long query(long long u,long long l,long long r,long long ql,long long qr,long long num){
	if(ql<=l&&r<=qr){
		long long pos=upper_bound(gbs[u].begin(),gbs[u].end(),num)-gbs[u].begin()-1;
//		cout<<pos<<'='<<endl;
		return (pos==-1?0:qzh[u][pos]);
	}
	long long mid=l+r>>1,ans=0;
	if(ql<=mid)ans+=query(u<<1,l,mid,ql,qr,num);
	if(qr>mid)ans+=query(u<<1|1,mid+1,r,ql,qr,num);
	return ans;
}
int main(){
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	build(1,1,n);
	long long q,lst=0;
	cin>>q;
	while(q--){
		long long l,r,x;
		cin>>l>>r>>x;
		l^=lst;
		r^=lst;
		x^=lst;
//		cout<<l<<" "<<r<<" "<<x<<endl;
		cout<<(lst=query(1,1,n,l,r,x))<<endl;
	}
}
