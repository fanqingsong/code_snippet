

#include <bits/stdc++.h>
using namespace std;

//#define  long long
int q1[5004][5004],q2[5004][5004];

void solve(){
	long long n;
	cin>>n;
	
	vector<long long>v(n+1);
	
	for(long long i=1;i<=n;i++){
		cin>>v[i];
	}
	
	for(long long i=1;i<=n;i++){//1-i <j
//		cout<<i<<endl;
		for(long long j=1;j<=n;j++){
			q1[i][j]=q1[i-1][j]+(v[i]<v[j]);
//			cout<<q1[i][j]<<" ";
		}
//		cout<<endl;
	}
	
	for(long long i=n;i>0;i--){//i-n <j
		for(long long j=n;j>0;j--){
			q2[i][j]=q2[i+1][j]+(v[i]<v[j]);
		}
	}
	
	long long ans=0;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(i==j){
				continue;
			}
			ans+=q1[i-1][j]*q2[j+1][i];
		}
	}
	
	cout<<ans<<endl;

	memset(q1, 0, sizeof(q1));
	memset(q2, 0, sizeof(q2));
}

signed main(){
	long long t;
	cin>>t;
	while(t--){
		solve();
	}
}
