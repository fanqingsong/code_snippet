#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>v(n),ve(m);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}for(int i=0;i<m;i++){
		cin>>ve[i];
	}sort(v.begin(),v.end());
	sort(ve.begin(),ve.end());
	int l=0,r=0;
	while(m-l>r){
		int nw;
		if(l==n){
			nw=ve[r]+1;
			r++;
		}else if(r==m){
			nw=v[l];
			l++;
		}
		else if(v[l]>ve[r]){
			nw=ve[r]+1;
			r++;
		}else{
			nw=v[l];
			l++;
		}if(m-l<=r){
			cout<<nw<<endl;
			return 0;
		}
	}
}
