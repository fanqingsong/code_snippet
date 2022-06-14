#include <bits/stdc++.h>
#include <vector>

using namespace std;

/*
https://atcoder.jp/contests/agc001/tasks/agc001_a
*/


int main(){
	int n;
	vector<int> l;
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		int first;
		int second;
		
		cin >> first >> second;
		
		l.push_back(first);
		l.push_back(second);
	}
	
	sort(l.begin(), l.end());
	
	int count = 0;
	for(int i=0; i<n; i++){
		int first_index = 2 * i;
		count += l[first_index];
	}
	
	cout << count << endl;
}
