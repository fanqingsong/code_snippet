#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>mp;
map<int,int>::iterator itr;
signed main(){
	int n,q,ans=0;
	cin>>n>>q;
	int qzh[100005]={0};
	mp[0]++;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		qzh[i]=(qzh[i-1]+num)%q;
		mp[qzh[i]]++;
	}for(itr=mp.begin();itr!=mp.end();itr++){
		ans+=(itr->second-1)*itr->second/2;
		ans%=1234567;
	}cout<<ans<<endl;
}
