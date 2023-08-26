#include <bits/stdc++.h>
using namespace std;
/*
Author fanchuanyu
date -
status WATLERECEMLEOLEUKEJFPE
*/
int b,e,a[500005];bool aup,alw;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int q;
	cin>>q;
	b=1;e=0;
	while(q--){
		int t,x;char c;
		cin>>t>>x>>c;
		if(t==1){
			if('a'<=c&&c<='z'){
				if(aup){
					e++;
					a[e]=x-1;
				}s[x-1]=c;
			}else{
				if(alw){
					e++;
					a[e]=x-1;
				}s[x-1]=c;
			}
		}else if(t==2){
			aup=0;alw=1;
			b=e+1;
		}else{
			alw=0;aup=1;
			b=e+1;
		}
	}if(aup){
		for(int i=0;i<n;i++){
			if(s[i]>='a'&&s[i]<='z'){
				s[i]=s[i]-'a'+'A';
			}
		}
		for(int i=b;i<=e;i++){
			s[a[i]]=s[a[i]]-'A'+'a';
		}
	}if(alw){
		for(int i=0;i<n;i++){
			if(s[i]>='A'&&s[i]<='Z'){
				s[i]=s[i]-'A'+'a';
			}
		}for(int i=b;i<=e;i++){
			s[a[i]]=s[a[i]]-'a'+'A';
		}
	}
	cout<<s<<endl;
}

