#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main(){
	int n;
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		if(!mp[m]){
			v.push_back(m);
		}
		mp[m]++;
	}
	sort(v.begin(),v.end());
	int l=0,r=v.size();
	bool ok=0;
	while(r-l>=3){
		int m;
		if(mp[v[l]]>=mp[v[r-1]]){
			mp[v[l]]-=mp[v[r-1]];
			mp[v[l+1]]+=mp[v[r-1]];
			mp[v[r-2]]+=mp[v[r-1]];
			mp[v[r-1]]=0;
			if(mp[v[l]]==0){
				l++;
			}
			if(r-l>2)r--;
			else{
				ok=1;
			}
		}else{
			mp[v[r-1]]-=mp[v[l]];
			mp[v[l+1]]+=mp[v[l]];
			mp[v[r-2]]+=mp[v[l]];
			mp[v[l]]=0;
			l++;
			if(r-l<3){
				ok=1;
			}
		}
	}
	cout<<(ok?"Mirko":"Slavko")<<endl;
	cout<<v[l]<<" "<<v[r-1]<<"\n";
}
