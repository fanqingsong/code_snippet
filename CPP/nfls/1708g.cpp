#include <bits/stdc++.h>
using namespace std;
int a[5002][5002],ans;
int main(){
	int n,r;
	cin>>n>>r;
	for(int i=0;i<n;i++){
		int x,y,v;
		cin>>x>>y>>v;
		a[x+1][y+1]+=v;
	}
	for(int i=1;i<=5001;i++){
		for(int j=1;j<=5001;j++){
			a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
		}
	}
	for(int i=r;i<=5001;i++){
		for(int j=r;j<=5001;j++){
			ans=max(ans,a[i][j]-a[i-r][j]+a[i-r][j-r]-a[i][j-r]);
		}
	}
	cout<<ans<<endl;
}
