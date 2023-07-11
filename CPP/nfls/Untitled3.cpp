#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>v;
int solve(int l,int r,int dw){
	if(l==r){
		return 1;
	}
	int ans=r-l+1;
	int mn=1e9;
	for(int i=l;i<=r;i++){
		mn=min(mn,v[i]);
	}
	int fnt=l,res=0;bool ok=0;
	for(int i=l;i<=r;i++){
		if(v[i]==mn){
			if(ok){
				ok=0;
				res+=solve(fnt,i-1,mn);
			}
		}else{
			if(!ok){
				fnt=i;
				ok=1;
			}
		}
	}if(ok==1){
		res+=solve(fnt,r,mn);
	}
	return min(ans,res+mn-dw);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		v.push_back(k);
	}
	cout<<solve(0,n-1,0);
}
