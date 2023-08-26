/*
Auther fanchuanyu
problem u313202
*/
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
map<int,vector<int> >mp;
signed main(){
	int n,q;
	cin>>n>>q;
	while(q--){
		string s;
		cin>>s;
		if(s=="Push"){
			int x,k;
			cin>>x>>k;
			mp[x].push_back(k);
		}else if(s=="Pop"){
			int x;
			cin>>x;
			mp[x].pop_back();
		}else if(s=="Copy"){
			int x,y;
			cin>>x>>y;
			while(mp[x].size()<mp[y].size()){
				mp[x].push_back(0);
			}while(mp[x].size()>mp[y].size()){
				mp[x].pop_back();
			}
			for(int i=0;i<mp[x].size();i++){
				mp[x][i]=mp[y][i];
			}
		}else{
			int x;
			cin>>x;
			if(mp[x].size()==0){
				cout<<-1<<endl;
			}
			cout<<mp[x][mp[x].size()-1]<<endl;
		}
	}
}
