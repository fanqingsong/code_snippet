#include <bits/stdc++.h>
using namespace std;

/*
dp[i][j] = ǰj��ƥ����t��ǰiλ������Ҫ���ѵ�����Ǯ��
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
        ���ڵ�j�鲻��ѡ������������Ҫ�Ȱ�j-1��Ļ��ѿ�����j��
		*/
		for(int i=0;i<=t.size();i++) dp[i][j]=dp[i][j-1];

		int a;
		cin>>a;
		
		while(a--){
			string s;
			cin>>s;
			
			/*
            ö���Ѿ�ƥ���˶���λ
            ����Ѿ�ƥ����0��λ�ã�����Ҫ��0λ��ʼƥ��
            ����Ѿ�ƥ����1��λ�ã�����Ҫ��1λ��ʼƥ��
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

