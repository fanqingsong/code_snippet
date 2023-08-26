#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
int cnt=0;
bool vis[200005];
int dfs(int n){
	if(vis[n]==1){
		return n;
	}else{
		cnt++;
		vis[n]=1;
		return dfs(mp[n]);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		mp[i]=a;
	}
	vector<int>v;
	int m=dfs(1),nw=mp[m];
	while(nw!=m){
		v.push_back(nw);
		nw=mp[nw];
	}
	cout<<v.size()+1<<endl;
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}cout<<m<<endl;
}
