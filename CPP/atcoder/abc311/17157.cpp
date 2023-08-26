#include <bits/stdc++.h>
using namespace std;
int dp[23][23][2];
int main(){
	int n,c,m;
	cin>>n>>c>>m;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			for(int k=v[i];k<=c;k++){
				dp[j][k][1]=max((int)max(dp[j][k][0],dp[j-1][c][0]+1),dp[j][k-v[i]][0]+1);
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=0;k<=c;k++){
				dp[j][k][0]=dp[j][k][1];
			}
		}
	}
	cout<<dp[m][c][0]<<endl;
}/*19 12 17
4
12
17
10
13
18
15
1
38
23
37
28
34
6
1
37
10
25
21*/
