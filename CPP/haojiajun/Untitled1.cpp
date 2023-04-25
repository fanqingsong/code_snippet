#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,s;
	
	cin >> n >> s;
	vector<int> a(n+1);
	
	for(int i=1; i<=n; i++){
		s = (s*345) % 19997;
		a[i] = s%200 + 1;
		cout << "a[" << i << "] = " << a[i] << endl;
	}
	
	bitset<20005> B(0);
	B.set(0);
	
	for(int i=1; i<=n; i++){
		B |= B << a[i];
	}
	
	cout << B.to_string() << endl;
	
	int sum = accumulate(a.begin(), a.end(), 0);
	cout << "sum =" << sum << endl;
	
	for(int j=(sum+1)/2; j<20005; ++j){
		if (B.test(j)){
			cout << j << endl;
			break;
		}
	}
	
	return 0;
}

