#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int n;
	char c;
	cin>>s>>n;
	c=n+'0';
	bool is=0;
	for(int i=0;i<s.size();i++){
		if(c>s[i]){
			is=1;
			string a=s.substr(0,i);
			a+=c;
			a+=s.substr(i,s.size()-i);
			s=a;
			break;
		}
	}
	if(is==0){
		s+=c;
	}
	bool ok=0;
	for(int i=1;i<s.size();i++){
		if(s[i]>s[i-1]){
			s.erase(i-1,1);
			ok=1;
			break;
		}
	}
	if(ok==0){
		s.erase(s.size()-1,1);
	}

    while(s.size()){
        if (s[0] == '0'){
            s.erase(0,1);
        } else {
            break;
        }
    }

	cout<<s<<endl;
}
