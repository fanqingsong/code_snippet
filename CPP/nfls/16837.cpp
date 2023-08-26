#include <bits/stdc++.h>
using namespace std;
#include <cmath>

int n,h[50001],q,mn[50001][21],st[50001][21],lg[50002]={1};
	
int main(){
//	cout << log(4)/log(2) << endl;
	
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>h[i];
		mn[i][0]=st[i][0]=h[i];
	}

	for(int i=1;i<=20;i++){
		for(int j=0;j+(1<<i)<=n;j++){
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
			mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
			
//			cout<<j<<" "<<(1<<i)<<" "<<st[j][i]<<" "<<mn[j][i]<<endl;
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		
//		cout<<lg[r-l+1]<<" "<<st[l][lg[r-l+1]-1]<<" "<<mn[l][lg[r-l+1]-1]<<endl;

		int p = (int)(log(r-l+1)/log(2));
//		cout<<((int)(log(r-l+1)/log(2)))<<" "<<st[l-1][p]<<" "<<st[r-(1<<p)][p]<<" "<<mn[l-1][p]<<endl;


		cout<<(int)(
		max(
			st[l-1][p],
			st[r-(1<<p)][p]
		)
		-
		min(
			mn[l-1][p],
			mn[r-(1<<p)][p])
		)<<endl;
	}
}
