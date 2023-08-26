#include <bits/stdc++.h>
using namespace std;
map<char,char>mp;
int main(){
	string s;
	mp['<']='>';
	mp['{']='}';
	mp['[']=']';
	mp['(']=')';
	cin>>s;
	int ans=0;
	stack<int>st;
	for(int i=0;i<s.size();i++){
		if(s[i]=='<'||s[i]=='('||s[i]=='['||s[i]=='{'){
			st.push(i);
		}else{
			if(st.size()==0){
				cout<<"Impossible"<<endl;
				return 0;
			}
			int n=st.top();
			if(mp[s[n]]!=s[i]){
				ans++;
			}st.pop();
		}
	}cout<<ans<<endl;
}
