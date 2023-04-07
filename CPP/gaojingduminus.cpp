#include <bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;

	//delete leading zero


	if(a==b){
		cout<<0<<endl;
		return 0;
	}
	
	if(b.size()>a.size()){
		swap(a,b);
		cout<<"-";
	}
	if(b.size()==a.size()&&b>a){
		swap(a,b);
		cout<<"-";
	}
	bool c=0;
	string ans;
	for(int i=1;i<=b.size();i++){
		int a0=a[a.size()-i]-'0';
		int b0=b[b.size()-i]-'0';
		if(b0+c<=a0){
			ans+=(char)'0'+a0-b0-c;
			c=0;
		}else{
			ans+=(char)'0'+10+a0-b0-c;
			c=1;
		}
	}
	for(int i=b.size()+1;i<=a.size();i++){
		int a0=a[a.size()-i]-'0';
		int b0=0;
		if(b0+c<=a0){
			ans+=(char)'0'+a0-b0-c;
			c=0;
		}else{
			ans+=(char)'0'+10+a0-b0-c;
			c=1;
		}
	}
	for(int i=ans.size()-1;i>0;i--){
		if(ans[i]=='0'){
			ans.erase(i,1);
		}else{
			break;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
}
