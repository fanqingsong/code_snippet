#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int n,m,k;
int ksm(int k,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans*=k;
			ans%=mod;
		}
		k*=k;
		k%=mod;
		b>>=1;
	}
	return ans;
}
int inv(int n){
    return ksm(n,mod-2);
}
signed main(){
    cin>>n>>m;
    n=inv(n);
    for(int i=1;i<=m;i++)k=((k+(1-(k*n)))%mod+mod)%mod;
    cout<<k<<endl;
}

