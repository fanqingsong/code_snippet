#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int v[500005], bit[500005], data[500005];

int n, m;

int lowBit(int j){
    return j & (-j);
}

int sum(int i){ // 前idx个数的和, logn
    // 这里的i从1开始编号
    int res = 0;
    while(i > 0){
        res += bit[i];
        i -= lowBit(i);
    }
    return res;
}

int sumRange(int i, int j) { //logn
    return sum(j) - sum(i-1);
}

void update(int i, int val) { //logn
    int diff = val - data[i];
    data[i] = val;
    // bit中下标从1开始
    while(i <= n){
        bit[i] += diff;
        i += lowBit(i);
    }
}

void print(){
	for(int i=1; i<=n; i++){
		cout << bit[i] << ",";
	}

	cout << endl;
}

int main() {
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		cin >> v[i];
	}

	for(int i=1; i<=n; i++){
		update(i, v[i]);
		
//		cout << "-------------" << endl;
//		cout << "update i=" << i << " with v[i]=" << v[i] << endl;
//		
//		print();
	}

	for(int i=0; i<m; i++){
		int action, x;
		cin >> action >> x;
		
		if (action == 1){
			// add k to x pos
			int k;
			cin >> k;
			
			update(x, k+data[x]);
			
//			cout <<"----- add k=" << k << " to x=" << x << endl;
//			print();
			
		} else if (action == 2){
			// query sum in the range of [x, y]
			int y;
			cin >> y;
			
			cout << sumRange(x, y) << endl;
		}
	}
}
