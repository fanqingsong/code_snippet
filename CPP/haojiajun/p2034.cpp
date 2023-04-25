#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <deque>
#include <stack>

int n,m;
stack<int> dql, dqr;


int main(){
	cin>>n>>m;

	for(int i=n; i>=1; i--){
		dqr.push(i);
	}
	
	int mcnt = 0;
	bool rightflag = true;
	
	while(dqr.size()+dql.size() > 1){
		int head = 0;
		if (rightflag){
			head = dqr.top();
			dqr.pop();
		} else {
			head = dql.top();
			dql.pop();
		}

//		cout << "pop one element = " << head << endl;

		mcnt++;
		if (mcnt == m){
//			cout << "out = " << head << endl;
			mcnt = 0;
		} else {
			if (rightflag){
				dql.push(head);
				if (dqr.size() == 0){
					mcnt--;
				}
			} else {
				dqr.push(head);
				if (dql.size() == 0) {
					mcnt--;
				}
			}
		}
		
		if (rightflag){
			if (dqr.size() == 0){
				rightflag = false;
			}
		} else {
			if (dql.size() == 0) {
				rightflag = true;
			}
		}
	}
	
	if (dql.size()){
		cout << dql.top() << endl;
	} else {
 		cout << dqr.top() << endl;
	}
}


