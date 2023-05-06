#include <bits/stdc++.h>
using namespace std;
#include <vector>

int n, r;
vector<int> a;

int main(){
	cin >> n >> r;

	for(int i=0; i<n; i++){
		a.push_back((r % 100)+1);
		
		r = (r*6807 + 2831) % 201701;
	}
	
	sort(a.begin(), a.end());

//	for(int i=0; i<n; i++){
//		cout << a[i] << " ";
//	}

	vector<int> cost(n, 0);
	
	cost[0] = a[0];
	for(int i=1; i<n; i++){
		cost[i] = cost[i-1];
		cost[i] += a[i];
	}

	int sum = 0;
	for(int i=0; i<n; i++){
		sum += cost[i];
	}

	cout << sum << endl;
}
