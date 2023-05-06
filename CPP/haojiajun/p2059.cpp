#include <bits/stdc++.h>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pq;
map<int, bool> added;

int main(){
	cin >> n;
	
	pq.push(1);
	added[1] = true;
	
	int cnt = -1;
	while(pq.size()){
		int top = pq.top();
		pq.pop();
//		cout << top << endl;
		
		cnt++;
		if (n == cnt){
			cout << top << endl;
			return 0;
		}

		int temp;

		temp = top*2;
		if (!added[temp]){
			pq.push(temp);
			added[temp] = true;
		}

		temp = top*3;
		if (!added[temp]){
			pq.push(temp);
			added[temp] = true;
		}
		
		temp = top*5;
		if (!added[temp]){
			pq.push(temp);
			added[temp] = true;
		}
		
		temp = top*7;
		if (!added[temp]){
			pq.push(temp);
			added[temp] = true;
		}

	}
	
	return 0;
}
