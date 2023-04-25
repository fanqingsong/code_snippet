#include <bits/stdc++.h>
#include <string>
using namespace std;

int n, k, s;

int list[25];

int cnt = 0;



int main(){
	cin >> n >> k >> s;

	for(int i=0; i<n; i++){
		s = (s*123) % 19997;
		list[i] = (s % 991) + 10;
	}
	
	dfs(0);
}




