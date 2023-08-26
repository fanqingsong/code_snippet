#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 100007;
struct node{
	int sm,maxx,qzd,hzd;
};
int n, m, a[maxn], lazy[maxn * 4], sum[maxn * 4],mx[maxn * 4],qsd[maxn*4],hsd[maxn*4];
void push_up(int n) {
	sum[n] = sum[2 * n] + sum[2 * n + 1];
	mx[n] = max(max(mx[2 * n] , mx[2 * n + 1]),hsd[2*n]+qsd[2*n+1]);
	qsd[n]=max(qsd[2*n],sum[2*n]+qsd[2*n+1]);
	hsd[n]=max(hsd[2*n+1],sum[2*n+1]+hsd[2*n]);
 }
void build(int u, int l, int r) {
//    lazy[u] = 0;
    if (l == r) {
        sum[u] =mx[u]=qsd[u]=hsd[u]= a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * u, l, mid);
    build(2 * u + 1, mid + 1, r);
    push_up(u);
}
node qry(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr){
    	node t;
    	t.maxx=mx[u];
    	t.hzd=hsd[u];
    	t.qzd=qsd[u];
    	t.sm=sum[u];
        return t;
	}
    if (ql > r || qr < l){
		node t;
		t.maxx=t.hzd=t.qzd=-2e9-1;t.sm=0;
        return t;
	}
    int ret = -2e9-1;
    int mid = (l + r) / 2;

	if (ql>mid){
		return qry(u*2+1,mid+1,r,ql,qr);
	} else if (qr<=mid){
		return qry(u * 2, l, mid, ql, qr);
	}

    node n=qry(u * 2, l, mid, ql, qr),m=qry(u*2+1,mid+1,r,ql,qr);
	node ans;
    ans.maxx= max(max(n.maxx,m.maxx),n.hzd+m.qzd);
    ans.qzd=max(n.qzd,n.sm+m.qzd);
    ans.hzd=max(m.hzd,m.sm+n.hzd);
    ans.sm=n.sm+m.sm;
    return ans;
}
void update(int u, int l, int r, int pos, int x) {
    if (l == r) {
        sum[u] += x;
        mx[u]+=x;
        qsd[u]+=x;
        hsd[u]+=x;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(u * 2, l, mid, pos, x);
    else
        update(u * 2 + 1, mid + 1, r, pos, x);
    push_up(u);
}
signed main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a[i + 1];
    }
    
    build(1, 1, t);
    
   
    
    int m;cin>>m;
    while (m--) {
        int op, c, lft, rgt;
        cin >> op >> lft >> rgt;
        if (op == 0) {
            update(1, 1, t, lft, rgt-a[lft]);
            a[lft]=rgt;
        } else {
            cout << qry(1,1,t,lft,rgt).maxx << endl;
        }
    }
}
