#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int>ans(200005),ind(200005),v;
vector<bool>vis(200005);
map<int,vector<int> >mp;

int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		mp[a].push_back(b);
		ind[b]++;
	}
	
	queue<int>q;
	
	for(int i=1;i<=n;i++){
		if(ind[i]==0){
			vis[i]=1;
			q.push(i);
		}
	}
	
	if(q.size()!=1){
		cout<<"No"<<endl;

		return 0;
	}

	while(true){
		int num=q.front();
		q.pop();

		v.push_back(num);
		
		if (v.size() == n){
			break;
		}
		
		for(int i=0;i<mp[num].size();i++){
			int next = mp[num][i];
			ind[next]--;
			
			if((!vis[next]) && ind[next]==0){
				vis[next] = 1;
				
				q.push(next);
			}
		}
		
		if(q.size()!=1){
			cout<<"No"<<endl;
			return 0;
		}
	}
	
	cout<<"Yes"<<endl;
	
	for(int i=0;i<v.size();i++){
		ans[v[i]]=i+1;
	}
	
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	
	cout<<endl;
}
