#include <bits/stdc++.h>
using namespace std;
long long cnt[5000];
int main(){
	int n;
	cin>>n;
	int sum=(n+1)*n/2;
	if(sum&1){
		cout<<0<<endl;
		return 0;
	}cnt[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=0;j--){
			cnt[j+i]+=cnt[j];
		}
	}
	cout<<cnt[sum/2]/2<<endl;
}
