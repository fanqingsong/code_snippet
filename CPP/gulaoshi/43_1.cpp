#include <bits/stdc++.h>
using namespace std;
int fa[200005],n,m,opr,a,b;string ans="";
int find(int d){return d==fa[d]?d:fa[d]=find(fa[d]);}
void merge(int a,int b){fa[find(b)]=find(a);}
int main(){
	cin>>n>>m;
	for(int i=0;i<=n*2;i++)fa[i]=i;
	for(int i=0;i<m;i++){
		cin>>opr>>a>>b;
		if(opr==1){merge(a,b);merge(a+n,b+n);if(find(a)==find(b+n)||find(b)==find(a+n)){cout<<-1;return 0;}
		}else if(opr==2){merge(a,b+n);merge(b,a+n);if(find(a)==find(b)){cout<<"-1";return 0;}
		}else{
			if(find(a)==find(b))ans+='Z';
			else if(find(a)==find(b+n)||find(b)==find(a+n))ans+='J';
			else ans+='K';
		}
	}
	for(int i=1;i<=n;i++)if(find(i)==find(i+n)){cout<<"-1";return 0;}
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
}
