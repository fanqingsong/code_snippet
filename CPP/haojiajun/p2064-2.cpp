#include <bits/stdc++.h>
using namespace std;
int main(){
	cout<<"153846 ";
	long long tpow=200000;
	for(int i=6;;i++){
		tpow*=10;
		long long n=tpow-8;
		if(n%13==0){
			n/=13;
			cout<<n<<"6";
			return 0;
		}
	}
}
