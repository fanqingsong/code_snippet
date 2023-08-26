#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define int long long

const int mod = 1227000000 - 1;
const int eps = 1e-9;
map<double, unordered_set<double> > mp;
map<double, unordered_set<double> >::iterator itr;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<double> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        mp[a[i]].insert(b[i]);
    }
    vector<int> v;
    for (itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->second.size() > 1) {
            v.push_back(((itr->second.size()) * (itr->second.size() - 1) / 2) % mod);
        }
    }
    long long ans = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            ans += v[i] * v[j];
            ans %= mod;
        }
    }
    cout << ans << endl;
    vector<double> p(n);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        x--;
        for (int i = 0; i < m; i++) {
            if (b[x] * b[x] + 4 * a[x] * p[i] >= 0) {
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < m; i++) {
            if (b[x] * b[x] + 4 * a[x] * p[i] < 0.0) {
                cout << "(0,0)&(0,0) ";
                continue;
            }
            int x1 = (-b[x] - sqrt(b[x] * b[x] + 4 * a[x] * p[i])) / (2 * a[x]),
                x2 = (-b[x] + sqrt(b[x] * b[x] + 4 * a[x] * p[i])) / (2 * a[x]);
            if (l - eps <= x1 && x1 <= r + eps && x1 != 0) {
                cout << "(" << x1 << "," << (p[i] / x1) << ")";
            } else {
                cout << "(0,0)";
            }
            cout << "&";
            if (l - eps <= x2 && x2 <= r + eps && x2 != 0) {
                cout << "(" << x2 << "," << (p[i] / x2) << ")";
            } else {
                cout << "(0,0)";
            }
            cout << " ";
        }
        cout << endl;
    }
}
