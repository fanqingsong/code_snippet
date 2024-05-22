#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],c[200005];
bitset<2505>f[70];
char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}
int main(){
	int n=read(),cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}for(int i=1;i<=n+1;i++){b[i]=read();
	}
	b[n+1]++;
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		c[i]=(b[i+1]-b[i]-1);
		c[i]=min(c[i],b[n+1]-b[i]-1);
		if(a[i]==0)cnt++;
		for(int j=1;j<=n;j++)if(a[j]>b[i])ans++;
		for(int j=1;j<=n;j++)if(a[j]>b[i]&&a[j]<b[i+1])c[i]--;
	}
	for(int i=0;i<=cnt;i++){
		f[i][ans]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt&&j<=c[i];j++){
			for(int k=cnt-1;k>=0;k--){
				f[k+1]|=f[k]<<i;
			}
		}
	}
	for(int i=0;i<=n*n;i++){
		if(f[cnt][i]&&abs(2*ans-n*n)>abs(n*n-2*i)){
			ans=i;
		}
	}
	cout<<(double)ans/n/n<<endl;
}
