#include <bits/stdc++.h>
using namespace std;
#include <stack>

int n, k;

stack<int> st;

int main(){
	cin>>n>>k;
	
	while(k>0){
		int r = k%5;
		st.push(r);
		
		k /= 5;
	}
	
	while(st.size()){
		int op = st.top();
		st.pop();
		
		if (op == 0){
			// do nothing
		} else if (op == 1){
			n += 100;
			
			if (n > 1000){
				n -= 1000;
			}
		} else if (op == 2){
			n -= 100;
			
			if (n < 0){
				n += 200;
			}
		} else if (op == 3){
			n /= 2;
		} else if (op == 4){
			n *= 4;
			
			if (n > 1000){
				n %= 1000;
			}
		}
	}
	
	cout << n << endl;
}
