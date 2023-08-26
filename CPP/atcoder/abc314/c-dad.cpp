#include <bits/stdc++.h>
using namespace std;
/*
Author fanchuanyu
date -
status WATLERECEMLEOLEUKEJFPE
*/
int tp[200005],kt[200005],fst[200005];
int main(){
	int n,m;
	cin>>n>>m;
	string s,tmp;
	cin>>s;tmp=s;
	for(int i=1;i<=n;i++){
		cin>>tp[i];
		if(kt[tp[i]]!=0){
			s[i-1]=tmp[kt[tp[i]]-1];
		}
		kt[tp[i]]=i;
		if(fst[tp[i]]==0){
			fst[tp[i]]=i;
		}
	}for(int i=1;i<=m;i++){
		s[fst[i]-1]=tmp[kt[i]-1];
	}
	cout<<s<<endl;
}

