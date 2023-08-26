#include <bits/stdc++.h>
using namespace std;
int dp[3005][3005];
int main(){
	string s;
	cin>>s;
	dp[0][0]=1;
	int mx=0;
	for(int i=1;i<=s.size();i++){
		for(int j=0;j<=mx;j++){
			if(s[i-1]=='?'){
				dp[i][j+1]+=dp[i-1][j];
				if(j!=0){
					dp[i][j-1]+=dp[i-1][j];
					dp[i][j-1]%=998244353;
				}
			}else if(s[i-1]==')'){
				if(j!=0){
					dp[i][j-1]+=dp[i-1][j];
				}
			}else{
				dp[i][j+1]+=dp[i-1][j];
			}
		}if(s[i-1]==')'){
			mx--;
		}else{
			mx++;
		}
	}
	cout<<dp[s.size()][0]<<endl;
}
