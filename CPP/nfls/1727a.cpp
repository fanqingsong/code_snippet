#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int ans[1000006],fac[1000006];
void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
signed init(){
	ans[1]=ans[0]=1;
	fac[1]=1;
	for(int i=2;i<=1000006;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	for(int i=2;i<=1000006;i++){
		ans[i]=((mod-(mod/i))*ans[mod%i])%mod;
	}for(int i=2;i<=1000006;i++){
		ans[i]*=ans[i-1];
		ans[i]%=mod;
	}
	return 0;
}signed main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<(fac[a]*ans[b])%mod*ans[a-b]%mod<<endl;
		cout<<fac[a]<<" "<<ans[b]<<" "<<ans[a-b]<<endl;
	}
}
