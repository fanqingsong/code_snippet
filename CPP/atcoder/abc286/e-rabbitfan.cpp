#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>>mp;

/*
dp[i][j][k]
i = 0 --> n-1  start city
j = 0 --> n-1  end city
k = 0 --> 1

dp[i][j][0] -- the number of segments of shortest road from city i to city j
dp[i][j][1] -- the accumulated value one the shortest road by souvenir
*/
long long dp[304][304][2];

int main(){
	int n;
	cin>>n;
	
	vector<long long> v(n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j][0]=n;
		}
	}
	
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char c;
			cin>>c;
			
			if(c=='Y'){
				mp[i].push_back(j);
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0;j<mp[i].size();j++){
			dp[i][mp[i][j]][0]=1;
			dp[i][mp[i][j]][1]=v[i]+v[mp[i][j]];
		}
		dp[i][i][0]=0;
		dp[i][i][1]=v[i];
	}

	/*
	floyd alogrithm
	https://www.cnblogs.com/lightsong/p/16974935.html
	*/
	for(int k=0; k<n; k++){
		for(int i=0;i<n;i++){
			if (k==i){
				continue;
			}

			for(int j=0;j<n;j++){
				if (k==i){
					continue;
				}

				if(i==j){
					continue;
				}
				
				if(dp[i][j][0]>dp[i][k][0]+dp[k][j][0]){
					dp[i][j][0]=dp[i][k][0]+dp[k][j][0];
					dp[i][j][1]=dp[i][k][1]+dp[k][j][1]-v[k];
				}
				else if(dp[i][k][0]+dp[k][j][0]==dp[i][j][0]){
					dp[i][j][1]=max(dp[i][j][1],dp[i][k][1]+dp[k][j][1]-v[k]);
				}
			}
		}
	}
	
	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		a--;b--;
		if(dp[a][b][0]==n){
			cout<<"Impossible"<<endl;
		}else{
			cout<<dp[a][b][0]<<" "<<dp[a][b][1]<<endl;
		}
	}
}
