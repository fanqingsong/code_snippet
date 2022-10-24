#include<bits/stdc++.h>
using namespace std;
int a[200001];
map<int,int> appr;

int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		appr[a[i]]++;
	}
	
	int ans=0;
	
	for(int i=0;i<n;i++){
		bool ok = false;
		int ai = a[i];
		
		if (ai == 1 && appr[ai] == 1){
			ans++;
			continue;
		}
		
		for(int j=1; j*j<=ai; j++){
			if (ai % j != 0){
				continue;
			}
			
			if(appr[j]>0){
				ok=true;
				break;
			}

			int mirror = ai/j;

			if(appr[mirror]>0 && j!=1){
				ok=true;
				break;
			}
			
			if(j==1){
				if(appr[mirror]>1){
					ok=true;
					break;
				}
			}
		}
		
		if(!ok){
//			cout<<a[i]<<endl;
			ans++;
		}
	}
	
	cout<<ans<<endl;
}
