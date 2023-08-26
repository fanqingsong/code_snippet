#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 200007;

int n, m, a[maxn],b[maxn],ans[maxn],sum[maxn * 4];
void push_up(int n) {
    sum[n] = sum[2 * n] + sum[2 * n + 1];
}
void build(int u, int l, int r) {

    if (l == r) {
    	sum[u]=1;
        return;
    }
	sum[u]=(r-l+1);
	int mid=(l+r)/2;
    build(2 * u, l, mid);
    build(2 * u + 1, mid + 1, r);
}
int qry(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        
        return sum[u];
    }
    if (ql > r || qr < l) {
        
        return 0;
    }
    int mid = (l + r) / 2;
    return qry(2*u,l,mid,ql,qr)+qry(2*u+1,mid+1,r,ql,qr);
}
void update(int u, int l, int r, int pos, int x) {
    if (l == r) {
        sum[u] += x;
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
	memset(ans,-1,sizeof(ans));
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a[i + 1] >> b[i + 1];
    }build(1,1,t);
	for(int i=t;i>0;i--){
		int l=1,r=t;
		while(l<r){
			int mid=(l+r)/2;
			int n=qry(1,1,t,1,mid);
			if(n==a[i]+1&&ans[mid]==-1){
				l=mid;
				r=mid;
			}else if(n>a[i]){
				r=mid;
			}else{
				if(l==mid){
					l=mid+1;
				}
				else l=mid;
			}
		}
		ans[l]=b[i];
		update(1,1,t,l,-1);
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<" ";
	}
}
