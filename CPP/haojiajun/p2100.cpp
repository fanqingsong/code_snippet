#include <bits/stdc++.h>
using namespace std;
string mut(string s,int n){
	int jw=0;string ans="";
	for(int i=1;i<=s.size();i++){
		int nm=(s[s.size()-i]-'0')*n+jw;
		jw=nm/10;
		ans+=('0'+(nm%10));
	}
	ans+=('0'+jw);
	reverse(ans.begin(),ans.end());
	while(ans.size()&&ans[0]=='0'){
		ans.erase(0,1);
	}
	return ans;
}
int main(){
	int a,n;
	cin>>a>>n;
	string ans="1";
	for(int i=0;i<n;i++){
		ans=mut(ans,a);
	}
	int c1=0,c2=0;
	for(int i=0;i<ans.size();i++){
		if((int)(ans[i]-'0')%2==0){
			c2++;
		}else{
			c1++;
		}
	}
//	cout<<ans<<endl;
	cout<<c1-c2<<endl;
}
