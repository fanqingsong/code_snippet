#include <bits/stdc++.h>
using namespace std;
const int bs=1145;
map<unsigned long long,bool>mp;
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		unsigned long long hsh=0,nbs=1;
		for(int i=0;i<s.size();i++){
			hsh*=(unsigned long long)bs;
			hsh+=s[i]-'a'+1;
			nbs*=(unsigned long long)bs;
		}
		int ans=1,hshl=hsh;
		while(mp[hsh]){
			hsh*=nbs;
			hsh+=hshl;
			ans++;
			if(!mp[hsh]){
				hsh/=(nbs+1);
				break;
			}
		}cout<<ans<<" "<<hsh<<endl;
		mp[hsh]=1;
	}
}
