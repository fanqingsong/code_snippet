#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <queue>

using namespace std;


int n, q;
priority_queue<int, vector<int>, greater<int> > wait;
set<int> called;

int main(){
	cin >> n >> q;
	
	for(int i=1; i<=n; i++){
		wait.push(i);
	}
	
	for(int i=0; i<q; i++){
		int e;
		cin >> e;
		
		if (e == 1){
			if (!wait.empty()){
				int smallest = wait.top();
				wait.pop();

				called.insert(smallest);
			}
		} else if (e == 2){
			int x;
			cin >> x;
			
			if (called.count(x) > 0){
				called.erase(x);
			}
		} else if (e == 3) {
			if (called.size() > 0){
				cout << *called.begin() << endl;
			}
		}
	}
}




