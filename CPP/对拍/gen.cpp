#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int mod=1e9+7,x=1,ans=0;
signed main()
{
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		ans=(ans*3)%mod;
		if(s[i]=='1')
		{
			ans=(ans+x)%mod;
			x=(x*2)%mod;
		}
	}
	cout<<(x+ans)%mod;
	return 0;
}
