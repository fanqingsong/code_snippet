#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, int> > lcn, rcn;
vector<int> v;
int n, m;
int ans = 1e18;
void dfs1(int l, int y, int t) {
    if (l >= n / 2 + 1) {
        lcn.push_back({ y, t });
        if (y == (1ll << (n + 1)) - 2) {
            ans = min(ans, t);
        }
    } else {
        dfs1(l + 1, y, t);
        dfs1(l + 1, y ^ v[l], t + 1);
    }
    return;
}
void dfs2(int l, int y, int t) {
    if (l > n) {
        rcn.push_back({ y, t });
        if (y == (1ll << (n + 1)) - 2) {
            ans = min(ans, t);
        }
    } else {
        dfs2(l + 1, y, t);
        dfs2(l + 1, y ^ v[l], t + 1);
    }
    return;
}
signed man() {
    cin >> n;
	if(n==0)return -1;
	m=n-1;
	v.clear();
	lcn.clear();
	rcn.clear();
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a] += (1ll << b);
        v[b] += (1ll << a);
    }
    for (int i = 1; i <= n; i++) {
        v[i] += (1ll << i);
    }
    dfs1(1, 0, 0);
    dfs2(n / 2 + 1, 0, 0);
    sort(lcn.begin(), lcn.end());
    int c = unique(lcn.begin(), lcn.end()) - lcn.begin();
    lcn.resize(c);
    sort(rcn.begin(), rcn.end());
    c = unique(rcn.begin(), rcn.end()) - rcn.begin();
    rcn.resize(c);
    for (int i = 0; i < lcn.size(); i++) {
        pair<int, int> p = { (1ll << (n + 1)) - 2 - lcn[i].first, -1e18 };
        int nm = lower_bound(rcn.begin(), rcn.end(), p) - rcn.begin();
        if (nm < 0 || rcn[nm].first + lcn[i].first != (1ll << (n + 1)) - 2) {
            continue;
        } else {
            ans = min(ans, lcn[i].second + rcn[nm].second);
        }
    }
    cout << ans << endl;
}
signed main(){
	while(1){
		int n=man();
		exit(0);
	}
}

