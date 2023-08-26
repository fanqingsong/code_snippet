#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1219;

int solve(int n){
	if(n==1){
		return 1;
	}
	return (n-1)*solve(n-1)%mod;
}
signed main(){
	int n;cin>>n;
	cout<<solve(n)<<endl;
}
