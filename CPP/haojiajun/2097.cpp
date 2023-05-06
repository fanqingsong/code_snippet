#include <bits/stdc++.h>
using namespace std;

int x, y, z;

int main(){
	cin >> x >> y >> z;
	
	int minn = min(x, y);
	minn = min(minn, z);
	
	for(int i=minn; i>0; i--){
		if(x%i == 0 && y%i == 0 && z%i == 0){
			cout << i << endl;
			return 0;
		}
	}
}
