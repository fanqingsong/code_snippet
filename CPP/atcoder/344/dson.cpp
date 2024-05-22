#include <bits/stdc++.h>
using namespace std;

/*
dp[i][j] = 前j组匹配了t的前i位，所需要花费的最少钱数
*/
int dp[105][105];

int main(){
	string t;
	cin>>t;

	memset(dp,0x3f,sizeof(dp));
	int n, inf=dp[0][0];
	
	cin>>n;

	dp[0][0]=0;

	for(int j=1; j<=n; j++){
		/*
        存在第j组不被选择的情况，所以要先把j-1组的花费拷贝到j组
		*/
		for(int i=0;i<=t.size();i++) dp[i][j]=dp[i][j-1];

		int a;
		cin>>a;
		
		while(a--){
			string s;
			cin>>s;
			
			/*
            枚举已经匹配了多少位
            如果已经匹配了0个位置，则需要从0位开始匹配
            如果已经匹配了1个位置，则需要从1位开始匹配
			*/
			for(int i=0; i+s.size()<=t.size(); i++){
				if(t.substr(i,s.size())==s){
					dp[i+s.size()][j]=min(dp[i+s.size()][j],dp[i][j-1]+1);
				}
			}
		}
	}
	
	int ans = dp[t.size()][n];
	
	if(ans==inf)puts("-1");
	else cout<<ans<<endl;
}
/*
things to check
0.delete cerr code or use '//'
1.initallize(especially multicases)
2.int overflow/long long mle
3.if make the ans is hard , try 2-divided
4.memory &b-&a
5.function canshu position
6.the format of input
7.size enough ?
8.the name of function
9.stop copying x0->y0
*/

