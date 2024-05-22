#include <bits/stdc++.h>
using namespace std;
int sqz(int a,int b){
	return (a+b-1)/b;
}
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	s=' '+s;
	int ans=1e9,cf=0,cl=0;
	for(int i=1;i<=n&&s[i]=='1';i++)cf++;
	for(int i=n;i&&s[i]=='1';i--)cl++;
	if(cf!=0)ans=min(ans,cf);
	if(cl!=0)ans=min(ans,cl);
	int lst=cf;
	for(int i=cf+1;i<n-cl+1;i++){
		if(s[i]=='0'){
			if(lst==i-1){
				lst=i;
				continue;
			}
			else{
				ans=min(ans,(i-lst)/2);lst=i;
			}
		}
	}
	if(ans==1e9)cout<<"0"<<"\n";
	else{
//	\cout<<ans<<cf;
		int res=0;
		if(cf)res+=sqz(cf,ans*2-1);
		if(cf!=n&&cl)res+=sqz(cl,ans*2-1);
		lst=cf;
//		cout<<res;
		for(int i=cf+1;i<n-cl+1;i++){
			if(s[i]=='0'){
				if(lst==i-1){
					lst=i;
					continue;
				}
				else{
					
					res+=sqz(i-lst-1,ans*2-1);lst=i;
				}
			}
		}
		cout<<res<<"\n";
	}
}
