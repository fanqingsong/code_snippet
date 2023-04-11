#include <bits/stdc++.h>
using namespace std;
#include <string>

int n;

int main(){
	cin >> n;
	
	int sum = 0;
	
	for(int i=2; i<n; i++){
		if(n % i == 0){
			sum += i;
		}
	}
	
	cout << sum << endl;
}


