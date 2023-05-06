#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
map<char,vector<char> >mp;
map<pair<char,char>,int>cus;
void dfs(char c,int t){
	ans=max(ans,t);
	for(int i=0;i<mp[c].size();i++){
		if(cus[make_pair(c,mp[c][i])]){
			cus[make_pair(c,mp[c][i])]--;
			dfs(mp[c][i],t+1);
			cus[make_pair(c,mp[c][i])]++;
		}
	}
}
signed main(){
	int n;
	cin>>n;
	string str;
	cin>>str;
	mp[str[0]].push_back(str[1]);
	cus[make_pair(str[0],str[1])]++;
	for(int i=1;i<n;i++){
		string s;
		cin>>s;
		mp[s[0]].push_back(s[1]);
		cus[make_pair(s[0],s[1])]++;
	}
	dfs(str[0],0);
	cout<<ans<<endl;
}
