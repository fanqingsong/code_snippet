#include <bits/stdc++.h>
using namespace std;
int cf[1000001], a[1000001];
map<pair<int,int>,bool>mp;
int main() {
    int n, p,h,k;
    cin >> n >>p>>h>> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        if(l>r){
        	swap(l,r);
		}if(mp[make_pair(l,r)]==1){
			continue;
		}
        cf[l+1]++;
        cf[r]--;
        mp[make_pair(l,r)]=1;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + cf[i];
        cout<<h-a[i]<<endl;
    }
}
