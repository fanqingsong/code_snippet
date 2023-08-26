#include <bits/stdc++.h>
using namespace std;
#define int long long
int cf[200001], a[200001],nm[200001];
signed main() {
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
    	cin>>nm[i];
	}sort(nm+1,nm+n+1);
    while (k--) {
        int l, r;
        cin >> l >> r;
        cf[l]++;
        cf[r + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + cf[i];
    }sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
    	ans+=a[i]*nm[i];
	}
	cout<<ans<<endl;
}
