#include <bits/stdc++.h>
using namespace std;
/*
Author fanchuanyu
date -
status WATLERECEMLEOLEUKEJFPE
*/
int c[105];
vector<int>v[105];
int main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		for(int j=0;j<c[i];j++){
			int k;
			cin>>k;
			v[k].push_back(i);
		}
	}
	int x,mn=1e9,cnt=0;cin>>x;
	for(int i=0;i<v[x].size();i++){
		mn=min(mn,c[v[x][i]]);
	}
	for(int i=0;i<v[x].size();i++){
		if(c[v[x][i]]==mn){
			cnt++;
		}
	}cout<<cnt<<endl;
	for(int i=0;i<v[x].size();i++){
		if(c[v[x][i]]==mn){
			cout<<v[x][i]<<" ";
		}
	}
}

