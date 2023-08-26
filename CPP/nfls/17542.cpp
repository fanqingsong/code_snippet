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
long long s,t;//Դ��ͻ��
long long cnt;//�ߵ���������0��ʼ��š�
long long Head[maxN],work[maxN];//ÿһ�������һ���ߵı��
long long Next[maxM*maxM];//ָ���Ӧ���ǰһ����
long long V[maxM*maxM];//ÿһ����ָ��ĵ�
long long W[maxM*maxM];bool mark[maxN];//ÿһ���ߵĲ���
long long Depth[maxN];//�ֲ�ͼ�б�����
long long dfs(long long u,long long dist)//u�ǵ�ǰ�ڵ㣬dist�ǵ�ǰ����
{
	mark[u]=1;
    if (u==t)//���Ѿ������㣬ֱ�ӷ���
        return dist;
    for (long long &i=work[u];i!=-1;i=Next[i])
    {
        if ((Depth[V[i]]==Depth[u]+1)&&(W[i]!=0)&&!mark[V[i]])//ע������Ҫ����ֲ�ͼ�Ͳ�����Ϊ0��������
        {
            long long di=dfs(V[i],min(dist,W[i]));//��������
            if (di>0)//������ɹ�
            {
                W[i]-=di;//����߼�
                W[i^1]+=di;//����߼�
                return di;//���ϴ���
            }
        }
    }
    return 0;//����˵��û������·������0
}
bool bfs()
{
    queue<long long> Q;//����һ��bfsѰ�ҷֲ�ͼʱ�Ķ���
    while (!Q.empty())
        Q.pop();
    memset(Depth,0,sizeof(Depth));
    Depth[s]=1;//Դ�����Ϊ1
    Q.push(s);
    do
    {
        long long u=Q.front();
        Q.pop();
        for (long long i=Head[u];i!=-1;i=Next[i])
            if ((W[i]>0)&&(Depth[V[i]]==0))//���ò�����Ϊ0����V[i]��δ������ȣ�����������Ȳ��������
            {
                Depth[V[i]]=Depth[u]+1;
                Q.push(V[i]);
            }
    }
    while (!Q.empty());
    return Depth[t]>0;
}
long long Dinic(){
    long long Ans=0;//��¼�������
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

