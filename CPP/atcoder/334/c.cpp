#include <bits/stdc++.h>
using namespace std;
long long dp[400005][2];
int main(){
    int n,k;
    cin>>n>>k;
    vector<long long>v;
    v.push_back(0);
    for(int i=0;i<k;i++){
        long long a;
        cin>>a;
        v.push_back(a);
    }

    for(int i=2;i<v.size();i++){
//      cout<<dp[i][0]<<" "<<dp[i][1]<<' ';
		if (i % 2 == 0){
			dp[i][0] = dp[i-2][0]+v[i]-v[i-1];
		}else {
			dp[i][1] = min(dp[i-1][0], dp[i-2][1]+v[i]-v[i-1]);
		}
 //      cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }

    cout<<dp[v.size()-1][k%2]<<endl;
}
