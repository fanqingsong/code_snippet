#pragma GCC optimize("2,3,Ofast,inline")
#include <bits/stdc++.h>
using namespace std;
namespace sub1{
	#define int long long
	int n,m,P,a[200005];
	char op[200005];
	int qpow(int x,int y){
		int ret=1;
		while(y){
			if(y&1)ret=ret*x%P;
			x=x*x%P;
			y>>=1;
		}
		return ret;
	}
	void solve(){
		cin>>n>>m>>P;
		for(int i=1;i<=n;++i){
			cin>>op[i]>>a[i];
		}
		int x,y;
		for(int i=1;i<=m;++i){
			cin>>x>>y;
			if(x==1){
				int tmp=y%P;
				for(int j=1;j<=n;++j){
					if(op[j]=='+')tmp=(tmp+a[j])%P;
					if(op[j]=='*')tmp=tmp*a[j]%P;
					if(op[j]=='^')tmp=qpow(tmp,a[j]);
				}
				cout<<tmp<<'\n';
			}
			else
				cin>>op[y]>>a[y];
		}
	}
	#undef int
}
namespace sub2{
	#define int long long
	const int N=2e5+5;
	int n,m,P,a[N];
	char op[N];
	int qpow(int x,int y){
		int ret=1;
		while(y){
			if(y&1)ret=ret*x%P;
			x=x*x%P;
			y>>=1;
		}
		return ret;
	}
	struct Segtree{
		int tr[N<<2][101];
		#define lc p<<1
		#define rc p<<1|1
		#define mid (l+r>>1)
		void up(int p){
			for(int i=0;i<P;i++)tr[p][i]=tr[rc][tr[lc][i]];
		}
		void build(int p,int l,int r){
			if(l==r){
				for(int i=0;i<P;i++)tr[p][i]=((op[l]=='+')?(i+a[l])%P:((op[l]=='*')?i*a[l]%P:qpow(i,a[l])));
				return ;
			}
			build(lc,l,mid);
			build(rc,mid+1,r);
			up(p);
		}
		void upd(int p,int l,int r,int x){
			if(l==r){
				for(int i=0;i<P;i++)tr[p][i]=((op[l]=='+')?(i+a[l])%P:((op[l]=='*')?i*a[l]%P:qpow(i,a[l])));
				return ;
			}
			if(x<=mid)upd(lc,l,mid,x);
			else upd(rc,mid+1,r,x);
			up(p);
		}
	}sgt;
	void solve(){
		cin>>n>>m>>P;
		for(int i=1;i<=n;i++){
			cin>>op[i]>>a[i];
		}
		sgt.build(1,1,n);
		int x,y;
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			if(x==1)cout<<sgt.tr[1][y%P]<<'\n';
			else{
				cin>>op[y]>>a[y];
				sgt.upd(1,1,n,y);
			}
		}
	}
}
namespace sub3{
	#define int long long
	const int N=2e5+5;
	int n,m,P,a[N];
	char op[N];
	struct Segtree{
		int tr[N<<2],tr2[N<<2];
		#define lc p<<1
		#define rc p<<1|1
		#define mid (l+r>>1)
		void up(int p){
			tr[p]=tr[lc]*tr[rc];
			tr2[p]=tr2[lc]*tr[rc]+tr2[rc];
			tr[p]%=P; tr2[p]%=P;
		}
		void build(int p,int l,int r){
			if(l==r){
				if(op[l]=='+')tr[p]=1,tr2[p]=a[l]%P;
				else tr[p]=a[l]%P,tr2[p]=0;
				return ;
			}
			build(lc,l,mid);
			build(rc,mid+1,r);
			up(p);
		}
		void upd(int p,int l,int r,int x){
			if(l==r){
				if(op[l]=='+')tr[p]=1,tr2[p]=a[l]%P;
				else tr[p]=a[l]%P,tr2[p]=0;
				return ;
			}
			if(x<=mid)upd(lc,l,mid,x);
			else upd(rc,mid+1,r,x);
			up(p);
		}
	}sgt;
	void solve(){
		cin>>n>>m>>P;
		for(int i=1;i<=n;i++){
			cin>>op[i]>>a[i];
		}
		sgt.build(1,1,n);
		int x,y;
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			if(x==1)cout<<(sgt.tr[1]*y%P+sgt.tr2[1])%P<<'\n';
			else{
				cin>>op[y]>>a[y];
				sgt.upd(1,1,n,y);
			}
		}
	}
}
namespace sub4{
	#define int long long
	const int N=2e5+5;
	int n,m,P,a[N];
	char op[N];
	int qpow(int x,int y){
		int ret=1;
		while(y){
			if(y&1)ret=ret*x%P;
			x=x*x%P;
			y>>=1;
		}
		return ret;
	}
	struct Segtree{
		int tr[N<<2];
		#define lc p<<1
		#define rc p<<1|1
		#define mid (l+r>>1)
		void up(int p){
			tr[p]=tr[lc]+tr[rc];
			tr[p]%=P;
		}
		void build(int p,int l,int r){
			if(l==r){
				if(op[l]=='+')tr[p]=a[l]%P;
				else tr[p]=0;
				return ;
			}
			build(lc,l,mid);
			build(rc,mid+1,r);
			up(p);
		}
		void upd(int p,int l,int r,int x){
			if(l==r){
				if(op[l]=='+')tr[p]=a[l]%P;
				else tr[p]=0;
				return ;
			}
			if(x<=mid)upd(lc,l,mid,x);
			else upd(rc,mid+1,r,x);
			up(p);
		}
		#undef lc
		#undef rc
		#undef mid
	}sgt1;
	struct Segtree2{
		int tr[N<<2];
		#define lc p<<1
		#define rc p<<1|1
		#define mid (l+r>>1)
		void up(int p){
			tr[p]=tr[lc]*tr[rc]%P;
		}
		void build(int p,int l,int r){
			if(l==r){
				if(op[l]=='*')tr[p]=a[l]%P;
				else tr[p]=1;
				return ;
			}
			build(lc,l,mid);
			build(rc,mid+1,r);
			up(p);
		}
		void upd(int p,int l,int r,int x){
			if(l==r){
				if(op[l]=='*')tr[p]=a[l]%P;
				else tr[p]=1;
				return ;
			}
			if(x<=mid)upd(lc,l,mid,x);
			else upd(rc,mid+1,r,x);
			up(p);
		}
		#undef lc
		#undef rc
		#undef mid
	}sgt2;
	struct Segtree3{
		int tr[N<<2];
		#define lc p<<1
		#define rc p<<1|1
		#define mid (l+r>>1)
		void up(int p){
			tr[p]=tr[lc]*tr[rc]%(P);
		}
		void build(int p,int l,int r){
			if(l==r){
				if(op[l]=='^')tr[p]=a[l]%(P);
				else tr[p]=1;
				return ;
			}
			build(lc,l,mid);
			build(rc,mid+1,r);
			up(p);
		}
		void upd(int p,int l,int r,int x){
			if(l==r){
				if(op[l]=='^')tr[p]=a[l]%(P);
				else tr[p]=1;
				return ;
			}
			if(x<=mid)upd(lc,l,mid,x);
			else upd(rc,mid+1,r,x);
			up(p);
		}
		#undef lc
		#undef rc
		#undef mid
	}sgt3;
	void solve(){
		cin>>n>>m>>P;
		for(int i=1;i<=n;i++){
			cin>>op[i]>>a[i];
		}
		sgt1.build(1,1,n);
		sgt2.build(1,1,n);
		sgt3.build(1,1,n);
		int x,y;
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			if(x==1){
				if(op[1]=='+')cout<<(sgt1.tr[1]+y)%P<<'\n';
				else if(op[1]=='*')cout<<(sgt2.tr[1]*y)%P<<'\n';
				else cout<<qpow(y,sgt3.tr[1])<<'\n';
			}
			else{
				cin>>op[y]>>a[y];
				sgt1.upd(1,1,n,y);
				sgt2.upd(1,1,n,y);
				sgt3.upd(1,1,n,y);
			}
		}
	}
}
namespace sub5{
	#define int long long
	const int N=2e5+5;
	int n,m,P,a[N];
	char op[N];
	int qpow(int x,int y,int PP){
		int ret=1;
		while(y){
			if(y&1)ret=ret*x%PP;
			x=x*x%PP;
			y>>=1;
		}
		return ret;
	}
	struct Segtree{
		int tr[N<<2][20],PP;
		#define lc p<<1
		#define rc p<<1|1
		#define mid (l+r>>1)
		void up(int p){
			for(int i=0;i<PP;i++)tr[p][i]=tr[rc][tr[lc][i]];
		}
		void build(int p,int l,int r){
			if(l==r){
				for(int i=0;i<PP;i++)tr[p][i]=((op[l]=='+')?(i+a[l])%PP:((op[l]=='*')?i*a[l]%PP:qpow(i,a[l],PP)));
				return ;
			}
			build(lc,l,mid);
			build(rc,mid+1,r);
			up(p);
		}
		void upd(int p,int l,int r,int x){
			if(l==r){
				for(int i=0;i<PP;i++)tr[p][i]=((op[l]=='+')?(i+a[l])%PP:((op[l]=='*')?i*a[l]%PP:qpow(i,a[l],PP)));
				return ;
			}
			if(x<=mid)upd(lc,l,mid,x);
			else upd(rc,mid+1,r,x);
			up(p);
		}
	}sgt[4];
	int p[4];
	pair<int,int> gcd(int x,int y){
		if(!y)return {x,0};
		pair<int,int> ret=gcd(y,x%y);
		return {ret.second,ret.first-x/y*ret.second};
	}
	void solve(){
		cin>>n>>m>>P;
		for(int i=1;i<=n;i++){
			cin>>op[i]>>a[i];
		}
		sgt[0].PP=7;
		sgt[1].PP=13;
		sgt[2].PP=17;
		sgt[3].PP=19;
		for(int i=0;i<4;i++)sgt[i].build(1,1,n);
		int x,y;
		p[0]=7,p[1]=13,p[2]=17,p[3]=19;
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			if(x==1){
				int ans[4];
				for(int i=0;i<4;i++)ans[i]=sgt[i].tr[1][y%sgt[i].PP];
				int res=0;
				for(int i=0;i<4;i++)res+=ans[i]*(P/p[i])*((gcd(P/p[i],p[i]).first%p[i]+p[i])%p[i]);
				cout<<res%P<<'\n';
			}
			else{
				cin>>op[y]>>a[y];
				for(int i=0;i<4;i++)sgt[i].upd(1,1,n,y);
			}
		}
	}
}
namespace sub6{
	#define int long long
	const int N=2e5+5;
	int n,m,P,a[N];
	char op[N];
	int qpow(int x,int y,int PP){
		int ret=1;
		while(y){
			if(y&1)ret=ret*x%PP;
			x=x*x%PP;
			y>>=1;
		}
		return ret;
	}
	struct Segtree{
		int tr[N<<2][20],PP;
		#define lc p<<1
		#define rc p<<1|1
		#define mid (l+r>>1)
		void up(int p){
			for(int i=0;i<PP;i++)tr[p][i]=tr[rc][tr[lc][i]];
		}
		void build(int p,int l,int r){
			if(l==r){
				for(int i=0;i<PP;i++)tr[p][i]=((op[l]=='+')?(i+a[l])%PP:((op[l]=='*')?i*a[l]%PP:qpow(i,a[l],PP)));
				return ;
			}
			build(lc,l,mid);
			build(rc,mid+1,r);
			up(p);
		}
		void upd(int p,int l,int r,int x){
			if(l==r){
				for(int i=0;i<PP;i++)tr[p][i]=((op[l]=='+')?(i+a[l])%PP:((op[l]=='*')?i*a[l]%PP:qpow(i,a[l],PP)));
				return ;
			}
			if(x<=mid)upd(lc,l,mid,x);
			else upd(rc,mid+1,r,x);
			up(p);
		}
	}sgt[3];
	int p[3];
	pair<int,int> gcd(int x,int y){
		if(!y)return {x,0};
		pair<int,int> ret=gcd(y,x%y);
		return {ret.second,ret.first-x/y*ret.second};
	}
	void solve(){
		cin>>n>>m>>P;
		for(int i=1;i<=n;i++){
			cin>>op[i]>>a[i];
		}
		sgt[0].PP=7;
		sgt[1].PP=11;
		sgt[2].PP=13;
		for(int i=0;i<3;i++)sgt[i].build(1,1,n);
		int x,y;
		p[0]=7,p[1]=11,p[2]=13;
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			if(x==1){
				int ans[3];
				for(int i=0;i<3;i++)ans[i]=sgt[i].tr[1][y%sgt[i].PP];
				int res=0;
				for(int i=0;i<3;i++)res+=ans[i]*(P/p[i])*((gcd(P/p[i],p[i]).first%p[i]+p[i])%p[i]);
				cout<<res%P<<'\n';
			}
			else{
				cin>>op[y]>>a[y];
				for(int i=0;i<3;i++)sgt[i].upd(1,1,n,y);
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin>>T;
	if(T>=1&&T<=3)sub1::solve();
	else if(T>=4&T<=9)sub2::solve();
	else if(T>=11&&T<=13)sub3::solve();
	else if(T>=14&&T<=15)sub6::solve();
	else if(T>=16)sub5::solve();
	else if(T==10)sub4::solve();
	else sub1::solve();
	return 0;
}

