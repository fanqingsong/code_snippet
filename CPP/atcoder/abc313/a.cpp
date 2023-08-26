#include <bits/stdc++.h>
using namespace std;

int n;
int p[104];

int solve(){
	int maxn = p[0];
	int maxi = 0;
	
	for(int i=1;i<n;i++){
		if (p[i] >= maxn){
			maxi = i;
			maxn = p[i];
		}
	}
	
	if (maxi == 0){
		return 0;
	}

	return maxn+1-p[0];
}

int main(){
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin >> p[i];
	}

	cout<<solve()<<endl;
}
