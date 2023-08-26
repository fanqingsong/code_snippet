#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		
		int cnt=0;
		for(int i=0;i<s.size();i++){
			if(s[i]==':'){
				cnt++;
			}
		}
		
		string ans="";
		int t=0;
		for(int i=s.size()-1;i>=0;i--){
			if(i!=0&&s[i]==':'&&s[i-1]==':'){
				for(int	j=t;j<4;j++){
					ans+='0';
				}
				ans+=':';
				t=0;
				for(int i=0;i<7-cnt;i++){
					ans+="0000:";
				}
			}else if(s[i]==':'){
				for(int	j=t;j<4;j++){
					ans+='0';
				}
				ans+=':';
				t=0;
			}else{
				t++;
				ans+=s[i];
			}
		}
		
		for(int	j=t;j<4;j++){
			ans+='0';
		}

		if(ans[ans.size()-1]==':'){
			ans.erase(ans.size()-1);
			while(1){
				ans=ans;
			}
		}
		
		reverse(ans.begin(),ans.end());
		if(ans[ans.size()-1]==':'){
			ans.erase(ans.size()-1);
			while(1){
				ans=ans;
			}
		}
		cout<<ans<<endl;
	}
}
