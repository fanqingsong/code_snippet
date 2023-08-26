#include <bits/stdc++.h>
using namespace std;
int v[100005],sum[100005*4],lazy1[100005*4],lazy2[100005*4];

void push_up(int u){
	sum[u]=sum[2*u]+sum[2*u+1];
}

void putlazy1(int u,int c,int l,int r){
	cout << "putlazy1\n";
	lazy1[u]+=c;
	sum[u]+=c*(r-l+1);
}

void putlazy2(int u,int c){
	cout << "putlazy2"<<u<<"\n";
//	sum[u]+=(lazy2[u]*sum[u]+lazy1[u])*(c-1);
	sum[u]*=c;
	lazy1[u]*=c;
	lazy2[u]*=c;
}

void push_down(int u,int l,int r){
	putlazy2(u*2,lazy2[u]);
	putlazy1(u*2,lazy1[u],l,(l+r)>>1);

	putlazy2(u*2+1,lazy2[u]);
	putlazy1(u*2+1,lazy1[u],((l+r)>>1)+1,r);
}

void build(int u,int l,int r){
	lazy1[u]=0;
	lazy2[u]=1;

	if(l==r){
		sum[u]=v[l];
		return;
	}
	int mid=(l+r)>>1;

	build(u*2,l,mid);
	build(u*2+1,mid+1,r);

	push_up(u) ;
}

int qry(int u,int l,int r,int ql,int qr){
	if(l>qr||r<ql){
		return 0;
	}

	if(l>=ql&&r<=qr){
		return sum[u];
	}

	int mid=(l+r)>>1;

	push_down(u,l,r);

	int res=0;
	res+=qry(u*2,l,mid,ql,qr);
	res+=qry(u*2+1,mid+1,r,ql,qr);
	return res;
}

void update1(int u,int l,int r,int ql,int qr,int c){
	cout << "update1\n";
	if(l>qr||r<ql){
		return;
	}
	
	if(l>=ql&&r<=qr){
		putlazy1(u,c,l,r);
		return;
	}
	int mid=(l+r)>>1;

	push_down(u,l,r);
	
	update1(u*2,l,mid,ql,qr,c);
	update1(u*2+1,mid+1,r,ql,qr,c);
	push_up(u);
	return;
}

void update2(int u,int l,int r,int ql,int qr,int c){
	cout << "update2\n";
	if(l>qr||r<ql){
		return;
	}

	if(l>=ql&&r<=qr){
		putlazy2(u,c);
		return;
	}

	push_down(u,l,r);
	int mid=(l+r)>>1;
	update2(u*2,l,mid,ql,qr,c);
	update2(u*2+1,mid+1,r,ql,qr,c);
	push_up(u);
	return;
}

int main(){
	int n,q;
	cin>>n>>q;

	for(int i=0;i<n;i++){
		cin>>v[1+i];
	}
	
	build(1,1,n);

	for(int i=1;i<n*4;i++){
		cout<<sum[i]<<endl;
	}
	while(q--){
		int tp,l,r;

		cin>>tp>>l>>r;
		if(tp==1){
			//add

			int lo;
			cin>>lo;
			update1(1,1,n,l,r,lo);
		}else if(tp==2){
			//mult

			int lo;
			cin>>lo;
			update2(1,1,n,l,r,lo);
		}else{
			//sum
			
			cout<<qry(1,1,n,l,r)<<endl;
			continue;
		}for(int i=1;i<n*4;i++){
			cout<<sum[i]<<endl;
		}
	}
}
