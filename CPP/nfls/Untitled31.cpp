#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int xl,xr,yl,yr,x,y,sum[1005][1005],mn[1005][1005],cnt1,cnt2,lth;
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
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
void queryy(int kx,int ky,int l,int r)
{
    if(l>=yl && r<=yr)
    {
        cnt1=max(cnt1,sum[kx][ky]);
        cnt2=min(cnt2,mn[kx][ky]);
        return;
    }
    int mid=l+r>>1;
    if(yl<=mid) queryy(kx,ky<<1,l,mid);
    if(yr>mid) queryy(kx,ky<<1|1,mid+1,r);
}

void queryx(int kx,int l,int r)
{
    if(l>=xl && r<=xr)
    {
        queryy(kx,1,1,lth);
        return;
    }
    int mid=l+r>>1;
    if(xl<=mid) queryx(kx<<1,l,mid);
    if(xr>mid) queryx(kx<<1|1,mid+1,r);
}

void changey(int kx,int ky,int l,int r,int n)
{
    if(l==r)
    {
        sum[kx][ky]=max(n,sum[kx][ky]);
        mn[kx][ky]=min(n,mn[kx][ky]);
        return;
    }
    int mid=l+r>>1;
    if(y<=mid) changey(kx,ky<<1,l,mid,n);
    
    else {changey(kx,ky<<1|1,mid+1,r,n);}

	sum[kx][ky]=max(sum[kx][ky],max(sum[kx][ky<<1],sum[kx][ky<<1|1]));
    mn[kx][ky]=min(mn[kx][ky],min(mn[kx][ky<<1],mn[kx][ky<<1|1]));
}

void changex(int kx,int l,int r,int n)
{
    changey(kx,1,1,lth,n);
    
    if(l==r) return;
    int mid=l+r>>1;
    if(x<=mid) changex(kx<<1,l,mid,n);
    else changex(kx<<1|1,mid+1,r,n);
}

int main(){
	int n=read(),b=read(),k=read();
	lth=n;
	memset(mn,5,sizeof(mn));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int t=read();
			x=i+1;y=j+1;
			changex(1,1,n,t);
		}
	}
	while(k--){
		xl=read();yl=read();
		cnt1=0;cnt2=1e9;
		xr=xl+b-1;
		yr=yl+b-1;
		queryx(1,1,n);
		write(cnt1-cnt2);
		putchar('\n');
	}
}
