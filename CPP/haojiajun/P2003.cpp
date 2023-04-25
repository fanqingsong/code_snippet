#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

int n, m, s;

int na[20], ma[20];
vector<int> all;


int main(){
	cin >> n >> m >> s;

	for(int i=0; i<n; i++){
		s = (s*543) % 19997;
		na[i] = (s % 100) + 1;
		
		all.push_back(na[i]);
	}

	for(int i=0; i<m; i++){
		s = (s*543) % 19997;
		ma[i] = (s % 100) + 1;
		
		all.push_back(ma[i]);
	}

	sort(all.begin(), all.end(), greater<int>());
	
	vector<int> arr(all.size());
	
	int arrb = -1;
	int arre = all.size();
	for(int i=0; i<all.size(); i++){
		if (i%2 == 0){
			arrb++;
			arr[arrb] = all[i];
		} else {
			arre--;
			arr[arre] = all[i];
		}
	}
	
//	for(int i=0; i<arr.size(); i++){
//		cout << arr[i] << " " << endl;
//	}
	
	int sum = 0;
	for(int i=0; i<arr.size(); i++){
		sum += (i+1) * arr[i];
	}
	
	cout << sum << endl;
}




