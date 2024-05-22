#include <bits/stdc++.h>
using namespace std;
vector<long long>son[1000025];
long long a[1000025],dep[1000025],cf[1000025];
struct node{
	long long l,r,x;
};
vector<node>v[1000025];
void dfs(long long u,long long s){
	for(node e:v[u]){
		if(e.r<d)continue;
		cf[max(e.l,dep[u])]+=e.x;
		cf[e.r+1]-=e.x;
	}
	s+=cf[dep[u]];
//	s%=1000000007ll;
	a[u]=s;
	for(long long v:son[u]){
		dep[v]=dep[u]+1;
		dfs(v,s);
	}
	for(node e:v[u]){
		if(e.r<d)continue;
		cf[max(e.l,dep[u])]-=e.x;
		cf[e.r+1]+=e.x;
	}
}
char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
long long read()
{
    long long x=0,f=1;
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
inline void write(long long a){
    if(a>9)write(a/10);
    putchar(a%10+'0');
}
int main(){
	long long n=read();
	for(long long i=2;i<=n;i++){
		long long f=read();
		son[f].push_back(i);
	}
	long long q=read();
	while(q--){
		long long u=read(),l=read(),r=read(),x=read();
		v[u].push_back({l,r,x});
	}
	dep[1]=1;
	dfs(1,0);
	long long ans=0;
	for(long long i=1;i<=n;i++){
		ans=(ans*12347ll+a[i])%1000000007ll;
	}cout<<ans;
}
