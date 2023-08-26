#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,d;
	cin>>n>>d;
	vector<string>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}int cnt=0,ans=0;
	for(int i=0;i<d;i++){
		bool ok=1;
		for(int j=0;j<n;j++){
			if(v[j][i]=='x'){
				ok=0;
				break;
			}
		}if(ok==1){
				cnt++;
				ans=max(ans,cnt);
			}else{
				cnt=0;
			}
	}
	cout<<ans<<endl;
}
