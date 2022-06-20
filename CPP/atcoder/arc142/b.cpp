#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

/*
https://atcoder.jp/contests/arc142/tasks/arc142_b
*/

int n, n2;

int sq[501][501] = {{0}};
bool used[250008] = {false};

bool check(int i, int j){
	if(i < 1 || i > n){
		return false;
	}
	
	if(j < 1 || j > n){
		return false;
	}
	
	int pv = sq[i][j];
	
	vector<int> adjs;
	for(int k=-1; k<=1; k++){
		int x = i + k;
		if (x < 1 || x > n){
			continue;
		}
			
		for(int l=-1; l<=1; l++){
			int y = j + l;
			if (y < 1 || y > n){
				continue;
			}
			
			if(i==x && j==y){
				continue;
			}
			
			adjs.push_back(sq[x][y]);
		}
	}
	
	int size = adjs.size();
	int lown = 0;
	int upn = 0;
	for(int m=0; m<size; m++){
		if(adjs[m] > pv){
			upn++;
		} else if (adjs[m] < pv){
			lown++;
		}
	}
	
	if(lown != upn){
		return true;
	}
	
	return false;
}

bool check_by_trigger(int i, int j){
	// check error
	if (i > 1){
		if(j > 1){
			// i-1, j-1
			if(!check(i-1, j-1)){
				return false;
			}
			
			// j == n
			if (j == n) {
				if (!check(i-1, j)){
					return false;
				}
			}
			
			// i == n
			if(i == n) {
				if(!check(i, j - 1)){
					return false;
				}
			}
			
			// i==n j==n
			if(i==n && j==n){
				if(!check(i, j)){
					return false;
				}
			}
		}
	}
	
	return true;	
}

bool backtracking(int i, int j){
//	cout << "i=" << i << " j=" << j << endl;
	
	if(i==n+1 && j==1){
		// print sq	
		for(int k=1; k<=n; k++){
			for(int l=1; l<=n; l++){
				cout << sq[k][l] << " ";
			}
			
			cout << endl;
		}
		
		return true;
	}
	
	for(int k=1; k<=n2; k++){
		if(used[k] == false){
			sq[i][j] = k;
			
			if(!check_by_trigger(i, j)){
				continue;
			}

			used[k] = true;			
			if(j == n){
				i ++;
				j = 1;
			} else {
				j ++;
			}
			
			bool ret = backtracking(i, j);
//			cout << "ret = " << ret << endl;
			
			if(ret == true){
				return true;
			}
			
			if(j == 1){
				i--;
				j = n;
			} else {
				j --;
			}	
			
			used[k] = false;
		}	
	}
	
	return false;
}

int main() {
	cin >> n;
	
	n2 = n*n;
		
	backtracking(1, 1);

	return 0;
}
