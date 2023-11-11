#include <bits/stdc++.h>
using namespace std;
int fa[200005],tag[200005],A[200005];
vector<int>v[200005];
int ff(int n){
	return fa[n]==n?n:fa[n]=ff(fa[n]);
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		fa[i]=i;
		tag[i]=0;
		v[i].push_back(i);
	}
	while(m--){
		int k;
		cin>>k;
		if(k==1){
			int a,b;
			cin>>a>>b;
			if(ff(a)==ff(b))continue;
			if(v[ff(a)].size()>v[ff(b)].size()){
				swap(a,b);
			}
			for(int i:v[ff(a)]){
				v[ff(b)].push_back(i);
				A[i]+=tag[ff(a)]-tag[ff(b)];
			}
			int fff=ff(a);
			fa[ff(a)]=ff(b);
			v[fff].clear();
		}else if(k==2){
			int a,b;
			cin>>a>>b;
			tag[ff(a)]+=b;
		}else{
			int a;
			cin>>a;
			cout<<A[a]+tag[ff(a)];
		}
	}
}
