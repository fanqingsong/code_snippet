#include <bits/stdc++.h>
using namespace std;
map<long long,vector<long long> >mp;
long long t[200005],u[200005];
bool b[200005],vis[200005];
void dfs(long long n){
	vis[n]=1;
	for(long long i=0;i<mp[n].size();i++){
		if(vis[mp[n][i]]){
			continue;
		}
		bool al;
		if(b[n]==1){
			al=0;
		}else{
			al=1;
		}
		b[mp[n][i]]=al;
		dfs(mp[n][i]);
	}
}
int main(){
	long long n,m;
	cin>>n>>m;

	for(long long i=0;i<m;i++){
		cin>>t[i]>>u[i];
		mp[t[i]].push_back(u[i]);
		mp[u[i]].push_back(t[i]);
	}
	b[1]=1;
	dfs(1);
	for(long long i=0;i<m;i++){
		if(b[t[i]]==b[u[i]]){
			cout<<0<<endl;
			return 0;
		}
	}
//	cout<<"111111111"<<endl;
	long long bl=0,wh=0;
	for(long long i=1;i<=n;i++){
		if(b[i]==0){
			bl++;
		}
		else{
			wh++;
		}
	}
//	cout<<bl<<"-----"<<wh<<endl;
	cout<<(long long)bl*wh-(long long)m<<endl;
}
