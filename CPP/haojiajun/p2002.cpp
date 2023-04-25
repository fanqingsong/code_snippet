#include <bits/stdc++.h>
using namespace std;

int n,sum,dp[35][65][800];

int main(){
	cin>>n>>sum;
	
	dp[0][n][400]=1;
	for(int i=1;i<=n;i++){
		for(int j=-1*n;j<=n;j++){
			for(int k=-1*n*(n-1)/2;k<=n*(n-1)/2;k++){
				dp[i][j+n][400+k] = dp[i-1][j+n-1][400+k-j]
					+dp[i-1][j+n+1][400+k-j];
			}
		}
	}
	
	long long cnt=0;
	for(int i=0;i<65;i++){
		cnt+=dp[n-1][i][400+sum];
	}
	
	cout<<cnt<<endl;
}
