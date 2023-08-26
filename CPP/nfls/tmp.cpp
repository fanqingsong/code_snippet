#include<bits/stdc++.h>
using namespace std;
inline int read()
{
   int x=0,f=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){
       if(ch=='-')
           f=-1;
       ch=getchar();
   }
   while(ch>='0'&&ch<='9'){
       x=(x<<1)+(x<<3)+(ch^48);
       ch=getchar();
   }
   return x*f;
}

int f[100001][40],b,n,m,p,l,r;
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    	f[i][0]=read();
    b=(int)(log(n)/log(2));
    for(int j=1;j<=b;j++)
        for(int i=1;i<=n-(1<<j)+1;i++)
            f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=m;i++)
    {
        l=read(),r=read();
        p=(int)(log(r-l+1)/log(2));
        printf("%d\n",min(f[l][p],f[r-(1<<p)+1][p]));
    }
    return 0;
}

