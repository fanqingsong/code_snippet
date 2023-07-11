#include <bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;

	char prev = 0;
	char cur;
	
	int count = 0;
	while(n--){
		cin >> cur;
		
		if (cur != prev){
			count++;
		}
		
		prev = cur;
	}
	
	count++;
	
	cout << count << endl;
}
