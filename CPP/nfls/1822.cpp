

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mid (l+r)/2
#define ls u*2,l,mid
#define rs u*2+1,mid+1,r
const int mod=1e9+7;
const int mx=100005;
int a[mx],rn[mx];
struct node{
	int ans,sum,len,lzy;
	node(){
		ans=sum=len=lzy=0;
	}
	void plz(int x){
		lzy+=x;
		lzy=(lzy%mod+mod)%mod;
		sum+=x*len;
		sum=(sum%mod+mod)%mod;
		ans+=(len*(len+1)/2)%mod*x;
		ans=(ans%mod+mod)%mod;
	}
}seg[mx*4];
void push_up(node &a,node b,node c){
	a.len=b.len+c.len;
	a.sum=b.sum+c.sum;
	a.sum=(a.sum%mod+mod)%mod;
	a.ans=c.ans+b.ans+c.len*b.sum;
	a.ans=(a.ans%mod+mod)%mod;
}
void push_down(int u){
	seg[u*2].plz(seg[u].lzy);
	seg[u*2+1].plz(seg[u].lzy);
	seg[u].lzy=0;
}
void update(int u,int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr){
		seg[u].plz(x);
		return ;
	}
	push_down(u);
	if(ql<=mid)update(ls,ql,qr,x);
	if(qr>mid)update(rs,ql,qr,x);
	push_up(seg[u],seg[u*2],seg[u*2+1]);
}
node query(int u,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		return seg[u];
	}
	push_down(u);
	if (ql>mid){
		return query(u*2+1,mid+1,r,ql,qr);
	} else if (qr<=mid){
		return query(u * 2, l, mid, ql, qr);
	}
    node n=query(u * 2, l, mid, ql, qr),m=query(u*2+1,mid+1,r,ql,qr);
	node ans;
	push_up(ans,n,m);
    return ans;

}
void build(int u,int l,int r){
	if(l==r){
		seg[u].len=1;
		seg[u].sum=seg[u].ans=a[l];
		return ;
	}
	build(ls);
	build(rs);
	push_up(seg[u],seg[u*2],seg[u*2+1]);
}
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];rn[i]=a[i];
		a[i]-=rn[i-1];
		a[i]=(a[i]%mod+mod)%mod;
	}
	build(1,1,n);
	while(m--){
		int op,l,r;
		cin>>op>>l>>r;
		if(op==1){
			if(l==1)cout<<query(1,1,n,1,r).ans<<endl;
			else cout<<query(1,1,n,1,r).ans-query(1,1,n,1,l-1).ans<<endl;
		}else{
			int x,b;
			cin>>x>>b;
			update(1,1,n,l,l,x);
			if(l!=r)update(1,1,n,l+1,r,-b);
			if(r!=n)update(1,1,n,r+1,r+1,-x+b*(r-l));
		}
	}

}
/*
things to check
5 3
3 9 8 5 1
1 1 5
0 3 5 2 5
1 2 4
1.initallize(especially multicases)
2.int overflow/long long mle
3.if make the ans is hard , try 2-divided
4.memory &b-&a
5.function canshu position
*/
