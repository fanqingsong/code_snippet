#include <bits/stdc++.h>
using namespace std;
#define int long long
bool isNp[1000006]={0};
signed main(){
	vector<int>v;

	for(int i=2;i<1000006;i++){
		if(!isNp[i]){
			for(int j=i;j*i<1000006;j++){
				isNp[i*j]=1;
			}
			v.push_back(i);
		}
	}
//	cout<<v.size()<<" "<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
	long long n,ans=0;
	cin>>n;
	for(long long i=0;i<v.size();i++){
		if(v[i]*v[i]>n){
			break;
		}
		
		for(int j=i+1;j<v.size();j++){
			if(v[i]*v[i]*v[j]>n){
				break;
			}
			
			for(int k=j+1;k<v.size();k++){
				if ( v[i]*v[i]*v[j]*v[k]*v[k] >n || v[i]*v[i]*v[j]*v[k]*v[k] <0 ){
					break;
				}
				
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
