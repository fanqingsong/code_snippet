#include <bits/stdc++.h>
#include <deque>

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
    deque<pair<int, int> > pntup;
    for (int i = 0; i < n; i++) {
        while (pntup.size() > 1) {
            pair<int, int> num = pntup.back();
            pntup.pop_back();
            if (qx(num, pntup.back()) * qy(v[i], num) < qx(v[i], num) * qy(num, pntup.back())) {
                pntup.push_back(num);
                break;
            }
        }
        pntup.push_back(v[i]);
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
            pair<int, int> num = pntup.front();
            pntup.pop_front();
            if (q[i]*num.first+num.second < q[i] * pntup.front().first+pntup.front().second) {
//			cout<<q[i]*num.first+num.second<<":"<<q[i] * pntup.top().first+pntup.top().second<<endl;
//			cout<<q[i]<<"-----"<<num.first<<" "<<num.second<<"/"<<pntup.top().first<<"\n";
				continue;
            } else {
                pntup.push_front(num);
                break;
            }
        }
        for (int j = 0; j < mp[q[i]].size(); j++)
            ans[mp[q[i]][j]] = pntup.front().first * (q[i]) + pntup.front().second;
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
}
