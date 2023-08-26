#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

int n, m;
map<int, vector<int>> stronger;
int ind[55];
bool vis[55];


int solve(){
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		
		ind[b]++;

		stronger[a].push_back(b);
	}

	map<int, int> indcnt;
	int zeroind = 0;
	for(int i=1; i<=n; i++){
		indcnt[ind[i]]++;

		if (ind[i] == 0){
			zeroind = i;
		}
	}
	
	if (indcnt[0] != 1){
		return -1;
	}

	queue<int> qq;
	qq.push(zeroind);
	
	while(!qq.empty()){
		int cur = qq.front();
		qq.pop();
		
		vis[cur] = true;
		
		vector<int>& nexts = stronger[cur];
		for(auto one: nexts){
			if (vis[one] == true){
				continue;
			}
			
			qq.push(one);
		}
	}

	for(int i=1; i<=n; i++){
		if (vis[i] == false){
			return -1;
		}
	}

	return zeroind;
}

int main(){
	cin>>n>>m;

	cout<<solve()<<endl;
}
