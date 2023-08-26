#pragma GCC optimize("Ofast")
#pragma GCC optimize("3")
#include <bits/stdc++.h>
using namespace std;

const long long inf=LONG_LONG_MAX;
long long read(){
	long long x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
void write(long long x) {
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
const long long maxN=2005;
const long long maxM=2005;
vector<int>v[2005];
long long s,t;//源点和汇点
long long cnt;//边的数量，从0开始编号。
long long Head[maxN],work[maxN];//每一个点最后一条边的编号
long long Next[maxM*maxM];//指向对应点的前一条边
long long V[maxM*maxM];//每一条边指向的点
long long W[maxM*maxM];bool mark[maxN];//每一条边的残量
long long Depth[maxN];//分层图中标记深度
long long dfs(long long u,long long dist)//u是当前节点，dist是当前流量
{
	mark[u]=1;
    if (u==t)//当已经到达汇点，直接返回
        return dist;
    for (long long &i=work[u];i!=-1;i=Next[i])
    {
        if ((Depth[V[i]]==Depth[u]+1)&&(W[i]!=0)&&!mark[V[i]])//注意这里要满足分层图和残量不为0两个条件
        {
            long long di=dfs(V[i],min(dist,W[i]));//向下增广
            if (di>0)//若增广成功
            {
                W[i]-=di;//正向边减
                W[i^1]+=di;//反向边加
                return di;//向上传递
            }
        }
    }
    return 0;//否则说明没有增广路，返回0
}
bool bfs()
{
    queue<long long> Q;//定义一个bfs寻找分层图时的队列
    while (!Q.empty())
        Q.pop();
    memset(Depth,0,sizeof(Depth));
    Depth[s]=1;//源点深度为1
    Q.push(s);
    do
    {
        long long u=Q.front();
        Q.pop();
        for (long long i=Head[u];i!=-1;i=Next[i])
            if ((W[i]>0)&&(Depth[V[i]]==0))//若该残量不为0，且V[i]还未分配深度，则给其分配深度并放入队列
            {
                Depth[V[i]]=Depth[u]+1;
                Q.push(V[i]);
            }
    }
    while (!Q.empty());
    return Depth[t]>0;
}
long long Dinic(){
    long long Ans=0;//记录最大流量
    while(bfs())
    {
    	for(int i=0;i<=cnt;i++){
			work[i]=Head[i];
		}
		memset(mark,0,sizeof(mark));
        while (long long d=dfs(s,inf))
        {
			memset(mark,0,sizeof(mark));
            Ans+=d;
		}
	}
    return Ans;
}
void init(){
    cnt=1;
    memset(Head,-1,sizeof(Head));
    memset(Next,-1,sizeof(Next));
}
void _Add(long long u,long long v,long long w){
    cnt++;
    Next[cnt]=Head[u];
    Head[u]=cnt;
    V[cnt]=v;
    W[cnt]=w;
}
void Add_Edge(long long u,long long v,long long w){
    _Add(u,v,w);
    _Add(v,u,0);
}int main(){
	init();
	long long n=read(),m=read(),tot=0;s=1;
	vector<long long>tmp(n);
//long long n;cin>>n;cin>>t;s=1;
	for(long long i=0;i<n;i++){
		tmp[i]=read();
//long long ss,e,c;cin>>ss>>e>>c;
		Add_Edge(1,i+2,tmp[i]);
		tot+=tmp[i];
	}for(long long i=0;i<m;i++){
		long long c=read();
		Add_Edge(i+2+n,n+m+2,c);
		for(long long j=0;j<n;j++){
			Add_Edge(j+2,i+2+n,1);
		}
	}t=n+m+2;
	long long ans=Dinic();
	if(ans==tot){
		cout<<1<<endl;
		for(int i=1;i<=n;i++){
			for(int j=Head[i+1];j!=-1;j=Next[j]){
				if(W[j]==0){
					v[i].push_back(V[j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
//			cout<<i<<endl;
			sort(v[i].begin(),v[i].end());
			for(int j=0;j<tmp[i-1];j++){
				write(v[i][j]-n-1);
				putchar(' ');
			}
			putchar('\n');
		}
	}else{
		cout<<0<<endl;
	}
}

