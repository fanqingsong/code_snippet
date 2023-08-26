#include <bits/stdc++.h>
using namespace std;
#define int long long
map<int,bool>xmp,ymp;
map<int,bool>::iterator itr;
map<int,int>xq,yq;
int a[2005][2005],ans;
signed main(){
	int n,t;
	cin>>n>>t;
	vector<int>xl(n),xr(n),yt(n),yb(n),ti(n);
	for(int i=0;i<n;i++){
		cin>>xl[i]>>yt[i]>>xr[i]>>yb[i]>>ti[i];
		xmp[xl[i]]=xmp[xr[i]]=ymp[yb[i]]=ymp[yt[i]]=1;
	}
	int xn=xmp.size(),yn=ymp.size(),cnt=1;
	vector<int>x(xn+1,0),y(yn+1,0);
	for(itr=xmp.begin();itr!=xmp.end();itr++){
		xq[itr->first]=cnt;
		x[cnt++]=itr->first;
	}cnt=1;
	for(itr=ymp.begin();itr!=ymp.end();itr++){
		yq[itr->first]=cnt;
		y[cnt++]=itr->first;
	}for(int i=0;i<n;i++){
		a[xq[xl[i]]][yq[yt[i]]]+=ti[i];
		a[xq[xl[i]]][yq[yb[i]]]-=ti[i];
		a[xq[xr[i]]][yq[yt[i]]]-=ti[i];
		a[xq[xr[i]]][yq[yb[i]]]+=ti[i];
	}for(int i=1;i<xn;i++){
		for(int j=1;j<yn;j++){
			a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
			if(a[i][j]>=t){
				ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
			}
		}
	}cout<<ans<<endl;
}
