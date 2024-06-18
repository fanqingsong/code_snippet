#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5e2, mod = 998244353;
ll C[N][N], k, a[N], dp[N][N];
void init() {
    C[0][0] = 1;
    for (int i = 1; i <= 1000; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
}
void solve() {
   cin >> k;
   for (int i = 1; i <= 26; i++) cin >> a[i];
   dp[0][0] = 1;
   for (int i = 1; i <= 26; i++) {
       for (int j = 0; j <= k; j++) {
           for (int l = 0; l <= a[i]; l++) {
               if (j + l > k) break;
               dp[i][j + l] = (dp[i][j + l] + dp[i - 1][j] * C[j + l][j] % mod) % mod;
           }
       }
   }
   ll ans = 0;
   for (int i = 1; i <= k; i++) {
       ans = (ans + dp[26][i]) % mod;
   }
   cout << ans << endl;
}
int main() {
    init();
    solve();
    return 0;
}

