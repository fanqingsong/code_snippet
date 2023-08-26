#include <bits/stdc++.h>
using namespace std;
int cf[1000001], a[1000001];
int main() {
    int n, k;
    cin >> n >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        cf[l]++;
        cf[r + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + cf[i];
        cout << a[i] << endl;
    }
}
