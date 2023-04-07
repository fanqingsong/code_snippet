#include <bits/stdc++.h>
using namespace std;
#include <string>

string a, b;
map<char, int> ac, bc;
map<int, int> acc, bcc;

int main(){
	cin >> a >> b;
	
	if (a.size() != b.size()){
		cout << 0 << endl;
		return 0;
	}
	
	for(int i=0; i<a.size(); i++){
		char one = a[i];
		ac[one]++;
	}

	for(int i=0; i<b.size(); i++){
		char one = b[i];
		bc[one]++;
	}

	for(auto it: ac){
		int cnt = it.second;
		acc[cnt]++;
	}

	for(auto it: bc){
		int cnt = it.second;
		bcc[cnt]++;
	}

	int sum = 1;
	for(auto it: acc){
		int anum = it.first;
		int acnt = it.second;
		
		int bcnt = bcc[anum];
		if (acnt != bcnt){
			cout << 0 << endl;
			return 0;
		}
		
		for(int j=1; j<=acnt; j++){
			sum *= j;
		}
	}
	
	cout << sum << endl;
}


