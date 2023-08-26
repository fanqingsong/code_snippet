#pragma GCC optimize("Ofast")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
const int mod=1e9+7;
int jyh[1000005];
int ans[1000006],fac[1000006];
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
}int c(int a,int b){
	return (fac[a]*ans[b]%mod)*ans[a-b]%mod;
}
signed main(){
	init();
	int n=read();
	jyh[2]=1;
	jyh[1]=0;
	jyh[0]=1;
	for(int i=2;i<=1000004;i++){
		jyh[i]=jyh[i-1]+jyh[i-2];
		jyh[i]=jyh[i]%mod;
		jyh[i]*=(i-1);
		jyh[i]%=mod;
	}
	while(n--){
		int a=read(),b=read();
		write(c(a,b)*jyh[a-b]%mod);
		putchar('\n');
	}
}
