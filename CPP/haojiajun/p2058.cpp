#include <bits/stdc++.h>
using namespace std;
#define int long long
string add(string a,string b){
	string ans="";
	int jw=0;
	if(a.size()<b.size()){
		swap(a,b);
	}
	for(int i=1;i<=b.size();i++){
		int n=(a[a.size()-i]-'0'+b[b.size()-i]-'0')+jw;
		jw=n/10;
		ans+=(n%10+'0');
	}
	for(int i=1;i<=b.size();i++){
		int n=(a[a.size()-i]-'0')+jw;
		jw=n/10;
		ans+=(n%10+'0');
	}
	ans+=jw;
	reverse(ans.begin(),ans.end());
	while(ans[0]=='0'){
		ans.erase(0,1);
	}
	return ans;
}
string mut(string s,int n){
	if(n>=10){
		return add(mut(s,n/10),mut(s,n%10));
	}
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
string solve(int k,int p){
	k-=p*(p-1)/2;
	int ext=k%p;
	int i=k/p;string ans="1";
	bool ok=0;
	for(int j=0;j<p-ext;j++,i++){

		ans=mut(ans,i);
	}for(int j=0;j<ext;j++,i++){
//		cout<<'*'<<i+1;
		ans=mut(ans,i+1);
	}
	return ans;
}
signed main(){
	int n;string res="0";
	cin>>n;
	for(int i=2;i*(i+1)/2<=n;i++){
		string ans=solve(n,i);
		if(ans.size()>res.size()){
			res=ans;
		}
		res=max(res,ans);
	}
	int ans=0;for(int i=0;i<res.size();i++){
		ans+=res[i]-'0';
	}
	cout<<ans<<endl;
}
