#include <bits/stdc++.h>
using namespace std;
struct rect{
	int xl,xr,yt,yb,id;
};
map<int,vector<rect> >xmp;
map<int,vector<rect> >ymp;
map<int,vector<rect> >zmp;
int ans[200005];
int qzh[105][105][105][3];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x1,y1,z1,x2,y2,z2;
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		xmp[x1].push_back({y1,z1,y2,z2,i});
		xmp[x2].push_back({y1,z1,y2,z2,i});
		ymp[y1].push_back({x1,z1,x2,z2,i});
		ymp[y2].push_back({x1,z1,x2,z2,i});
		zmp[z1].push_back({y1,x1,y2,x2,i});
		zmp[z2].push_back({y1,x1,y2,x2,i});
	}
	for(int i=1;i<=100;i++){
		for(int j=0;j<xmp[i].size();j++){
			qzh[xq[xl[i]]][yq[yt[i]]] += ti[i];
        	qzh[xq[xl[i]]][yq[yb[i]]] -= ti[i];
        	qzh[xq[xr[i]]][yq[yt[i]]] -= ti[i];
        	qzh[xq[xr[i]]][yq[yb[i]]] += ti[i];
		}
	}
}
