#include <bits/stdc++.h>
using namespace std;int pre[200005],i,n,suf[200005],a[200005],ans;int main(){cin>>n;for(i=1;i<=n;i++)cin>>a[i],pre[i]=min(pre[i-1]+1,a[i]);for(i=n;i>=1;i--)suf[i]=min(suf[i+1]+1,a[i]),ans=max(ans,min(pre[i],suf[i]));cout<<ans;}
