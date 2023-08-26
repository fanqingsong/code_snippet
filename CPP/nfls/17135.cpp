#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 200007;
int a[maxn], lazy[maxn * 4], sum[maxn * 4];

void putlazy(int u, int l, int r, int x) {
    lazy[u] += x;
    sum[u] += x;
}

void push_up(int n)
{
	sum[n] = max(sum[2 * n] , sum[2 * n + 1]);
}

void push_down(int u, int l, int r) {
    int mid = (l + r) / 2;

    putlazy(2 * u, l, mid, lazy[u]);
    putlazy(2 * u + 1, mid + 1, r, lazy[u]);

    lazy[u] = 0;
}

void build(int u, int l, int r) {
	lazy[u] = 0;

    if (l == r) {
        sum[u] = a[l];

        return;
    }

    int mid = (l + r) / 2;

    build(2 * u, l, mid);
    build(2 * u + 1, mid + 1, r);

    push_up(u);
}

int qry(int u, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return sum[u];

    if (ql > r || qr < l)
        return -1e9;

    push_down(u, l, r);

    int ret = 0;
    int mid = (l + r) / 2;

	return  max(qry(u * 2, l, mid, ql, qr),qry(u * 2 + 1, mid + 1, r, ql, qr));

//	return ret;
}

void update(int u, int l, int r, int lp, int rp, int x) {
    if (lp > r || l > rp) {
        return;
    }

    if (lp <= l && rp >= r) {
        putlazy(u, l, r, x);
        return;
    }

    push_down(u, l, r);

    int mid = (l + r) / 2;
    update(u * 2, l, mid, lp, rp, x);
    update(u * 2 + 1, mid + 1, r, lp, rp, x);

    push_up(u);
}

signed main() {
    int t,m;
    cin >> t>>m;
    for (int i = 0; i < t; i++) {
        cin >> a[i + 1];
    }

    build(1, 1, t);

    for (int i = 0; i < m; i++) {
        int op, c, lft, rgt;
        cin >> op >> lft >> rgt;

        if (op == 1) {
        	cin>>c;
            update(1, 1, t, lft, rgt, c);
        } else {
            cout << qry(1, 1, t, lft, rgt)  << endl;
        }
    }
}
