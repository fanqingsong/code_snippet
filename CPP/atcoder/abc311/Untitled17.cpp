#include <bits/stdc++.h>
using namespace std;
#define int long long
int qx(pair<int,int>a,pair<int,int>b){
	return a.first-b.first;
}int qy(pair<int,int>a,pair<int,int>b){
	return a.second-b.second;
}map<int,int>mp;
signed main(){
	int n,m,cnt=0;
	cin>>n>>m;
	vector<pair<int,int> >v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}

	sort(v.begin(),v.end());
	
//	for(int i=0;i<n;i++){
//		if(v[i].first==0&&v[i].second==0){
//			cnt++;
//		}
//	}
//	cout<<cnt<<endl;

	stack<pair<int,int> >pntup;

	for(int i=0;i<n;i++){
		while(pntup.size()>1){
			pair<int,int> num=pntup.top();
			pntup.pop();
			if(qx(num,pntup.top())*qy(v[i],num)>=qx(v[i],num)*qy(num,pntup.top())){
//				cout << ": first=" << num.first << " second="<< num.second << endl;
				pntup.push(num);
				break;
			}
		}
		pntup.push(v[i]);
	}
	
	vector<int> q(m),ans(m);
	
	for(int i=0;i<m;i++){
		cin>>q[i];mp[q[i]]=i;
	}
	
	sort(q.begin(),q.end());
	
	reverse(q.begin(),q.end());

	for(int i=0;i<q.size();i++){
		while(pntup.size()>1){
			pair<int,int>num=pntup.top();
			pntup.pop();
			if(qy(pntup.top(),num)<=q[i]*qx(pntup.top(),num)){
				continue;
			}else{
				pntup.push(num);
				break;
			}
		}

		cout <<"mp[q[i]]="<<mp[q[i]] << endl;
		ans[mp[q[i]]]=pntup.top().first * (q[i])+pntup.top().second;
	}
	
	for(int i=0;i<m;i++){
		cout<<ans[i]<<endl;
	}
}
