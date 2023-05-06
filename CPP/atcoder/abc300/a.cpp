#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<int> c;

int main(){
	cin >> n >> a >> b;
	int sum = a + b;
	
	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;
		
		c.push_back(temp);
		
		if (sum == temp){
			cout << i+1 << endl;
			return 0;
		}
	}
	
	
}
