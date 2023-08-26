#include <bits/stdc++.h>
using namespace std;
bool c[3005][3005];
int qzh[3005][3005];
int main(){
	int h,w,n;long long ans=0;
	cin>>h>>w>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		c[a][b]=1;
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			qzh[i][j]=c[i][j]+qzh[i-1][j]+qzh[i][j-1]-qzh[i-1][j-1];
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(c[i][j]==1){
				continue;
			}
			int l=0,r=min(h-i,w-j);
			while(l<=r){
				int mid=(l+r)/2;
				if(qzh[i+mid][j+mid]-qzh[i-1][j+mid]-qzh[i+mid][j-1]+qzh[i-1][j-1]==0){
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
			ans+=l;
		}
	}
	cout<<ans<<endl;
}
