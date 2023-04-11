#include <bits/stdc++.h>
using namespace std;
#include <string>

int k, m;

int main(){
	cin >> k >> m;

	int sum = 0;

	int power = 1;
	int square;
	for(int i=2; i<=m; i++){
		power *= 2;
		square = power;
//
//		cout << "i = " << i << endl;
//		cout << "square = " << square << endl;

		if (i >=k && i<= m){
			sum += square;
		}
	}

	string s = to_string(sum);
	if (s.size()<=6){
		cout << sum << endl;
	} else {
		cout << s[0] << s[1] << s[2] << "," << s[s.size()-3] << s[s.size()-2] << s[s.size()-1] << endl;
	}
	
}


