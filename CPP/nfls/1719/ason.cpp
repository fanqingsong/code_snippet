#include <bits/stdc++.h>
using namespace std;
#define int long long
int qx(pair<int, int> a, pair<int, int> b) { return a.first - b.first; }
int qy(pair<int, int> a, pair<int, int> b) { return a.second - b.second; }
map<int, vector<int> > mp;
signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    stack<pair<int, int> > pntup;
    for (int i = 0; i < n; i++) {
        while (pntup.size() > 1) {
            pair<int, int> num = pntup.top();
            pntup.pop();
            if (qx(num, pntup.top()) * qy(v[i], num) > qx(v[i], num) * qy(num, pntup.top())) {
                pntup.push(num);
                break;
            }
        }
        pntup.push(v[i]);
    }
    vector<int> q(m), ans(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i];
        mp[q[i]].push_back(i);
    }
    sort(q.begin(), q.end());
    int c = (unique(q.begin(), q.end()) - q.begin());
    for (int i = 0; i < c; i++) {
        while (pntup.size() > 1) {
            if()
        }
        for (int j = 0; j < mp[q[i]].size(); j++)
            ans[mp[q[i]][j]] = pntup.top().first * (q[i]) + pntup.top().second;
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
}
