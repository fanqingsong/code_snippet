#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,q;
	cin>>n>>q;
	int qzh[100005]={0};
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		qzh[i]=qzh[i-1]+num;
	}while(q--){
		int l,r;
		cin>>l>>r;
		cout<<qzh[r]-qzh[l-1]<<endl;
	}
}
