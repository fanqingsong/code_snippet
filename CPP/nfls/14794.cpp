#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}
signed main() {
    int n, m, i = 0, ans = 0;
    cin >> n >> m;
    vector<pair<int, int> > ps(n, { 1e18, 1e18 });
    while (n--) {
        cin >> ps[i].first >> ps[i].second;
        if (ps[i].second >= ps[i].first) {
            ps[i].second = ps[i].first = 1e18;
        }
        else {
			i++;
		}
    }
    sort(ps.begin(), ps.end(), cmp);
    n = 0;
    ps.resize(i);
    //	for(int j=0;j<ps.size();j++){
    //		cout<<ps[j].first<<"= ="<<ps[j].second<<endl;
    //	}
    while (ps.size()) {
        pair<int, int> nw = ps[ps.size() - 1];
        ps.pop_back();
        if (nw.first == -1) {
            continue;
        }
        if (ps.size() == 0 || nw.first > ps[ps.size() - 1].second) {
            ans += nw.second - nw.first;
            //			cout<<nw.second<<"-"<<nw.first<<endl;
        } else {
            ps[ps.size() - 1].second = nw.second;
        }
    }
    cout << m + ans * 2 << endl;
} /*
 3 5
 4 1
 4 2
 5 3
 */

