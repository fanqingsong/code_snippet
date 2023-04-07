#include <bits/stdc++.h>
using namespace std;
#include <string>

int n;

bool ishuiwen(int num){
	string s = to_string(num);
	
//	cout << s << endl;
	
	for(int i=0; i<s.size()/2; i++){
		if (s[i] != s[s.size()-i-1]){
			return false;
		}
	}

	return true;
}

int main(){
	cin >> n;
	
	int sum = 0;
	for(int i=1; i<=n; i++){
		if (ishuiwen(i)){
			sum += 1;
		}
	}
	
	cout << sum << endl;
}
