#include <bits/stdc++.h>
using namespace std;
long long dp[1000006];
int tot,hd[1000006],to[2000006],nxt[2000006];
const long long mod=1e9+7;
void add(int u,int v){
	tot++;
	to[tot]=v;nxt[tot]=hd[u];hd[u]=tot;
}
void dfs(int n,int f){
    long long mtp=2,sum=0;
    for(int i=hd[n];i!=0;i=nxt[i]){
        int v=to[i];
        if(v==f)continue;
        dfs(v,n);
        sum=(sum+dp[v])%mod;
        mtp=(mtp*(dp[v]+1))%mod;
    }
    dp[n]=mtp-sum-1;
    dp[n]=(dp[n]%mod+mod)%mod;
    return ;
}
int main(){
	memset(hd,0,sizeof(hd));
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
    }dfs(1,0);
    printf("%lld",dp[1]);
}

