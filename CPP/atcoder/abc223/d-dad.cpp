#include <bits/stdc++.h>
using namespace std;
map<long long,set<long long> >ed;
map<long long,long long>deg;
priority_queue<long long,vector<long long>,greater<long long> >pq;
signed main(){
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<m;i++){
		long long a,b;
		cin>>a>>b;
		deg[b]++;
		int sz=ed[a].size();
		ed[a].insert(b);
		if(ed[a].size()==sz){
			deg[b]--;
		}
	}
	for(long long i=1;i<=n;i++){
		if(deg[i]==0){
			pq.push(i);
			deg[i]--;
		}


	}
	vector<long long>v;
	long long cnt=0;
	while(!pq.empty()){
		long long q=pq.top();
		vector<long long>tmp;
		for(auto i:ed[q]){
			deg[i]--;
//			cout<<i<<endl;
			if(deg[i]==0){
				tmp.push_back(i);
				deg[i]--;
			}
		}
		cnt++;
		v.push_back(q);
		pq.pop();
		for(long long i=0;i<tmp.size();i++){
			pq.push(tmp[i]);
		}
	}
	if(cnt!=n){
		cout<<-1<<endl;
		return 0;
	}
	for(long long i=0;i<n;i++){
		cout<<v[i]<<' ';
	}
}
