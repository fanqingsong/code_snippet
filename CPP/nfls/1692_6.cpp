#include <bits/stdc++.h>
using namespace std;
long long q1[50005], p1[50005];
long long q2[50005], p2[50005];

bool mycomp(pair<long long, int> e, int value) { return e.first<value; }

int main() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, int> > v1(n), v2(m);
    
    for (int i = 0; i < n; i++) {
        cin >> v1[i].first;
        v1[i].second = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> v2[i].first;
        v2[i].second = i;
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 1; i <= n; i++) {
        q1[i] = q1[i - 1] + v1[i - 1].first;
        q2[i] = q2[i - 1] + v1[i - 1].second;
    }
    
    for (int i = 1; i <= m; i++) {
        p1[i] = p1[i - 1] + v2[i - 1].first;
        p2[i] = p2[i - 1] + v2[i - 1].second;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        auto lptr = lower_bound(v2.begin(), v2.end(), v1[i].first, mycomp);
        int l = (*lptr).second;
        ans += l * v1[i].first * v1[i].second;
        ans -= v1[i].first * p2[l];
        ans -= v1[i].second * p1[l];
        ans -= (m - l) * v1[i].first * v1[i].second;
        ans += v1[i].first * (p2[m] - p2[l]);
        ans += v1[i].second * (p1[m] - p1[l]);
    }
    
    for (int i = 0; i < m; i++) {
        auto lptr = lower_bound(v1.begin(), v1.end(), v2[i].first, mycomp);
        int l = (*lptr).second;
        ans += (2 * l - n) * v2[i].first * v2[i].second;
    }
    
    cout << ans << endl;
}
