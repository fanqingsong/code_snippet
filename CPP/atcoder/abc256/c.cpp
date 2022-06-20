#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>

/*
https://atcoder.jp/contests/abc256/tasks/abc256_c
*/

int h1, h2, h3, w1, w2, w3;

int h[4] = {0};
int w[4] = {0};

int ub[4][4] = {{0}};

int sq[4][4] = {{0}};

int counter = 0;


void backtracking(int i, int j){
	if(i==4 && j==1){
		// w1 test
		int w1 = 0;
		for(int i =1; i<=3; i++){
			w1 += sq[i][1];
		}

		// w2 test
		int w2 = 0;
		for(int i =1; i<=3; i++){
			w2 += sq[i][2];
		}

		// w3 test
		int w3 = 0;
		for(int i =1; i<=3; i++){
			w3 += sq[i][3];
		}

		if(w[1] == w1 && w[2] == w2 && w[3] == w3){
			counter ++;
		}
				
		return;
	}
	
	int limit;
	if(j == 1){
		if (i == 1){
			limit = ub[1][1];			
		} else if (i == 2) {
			limit = min(ub[2][1], w[1] - sq[1][1] - 1);
		} else if (i == 3){
			limit = min(ub[3][1], w[1] - sq[1][1] - sq[2][1]);
		}
	}else if(j == 2){
		if(i == 1){
			limit = min(ub[1][2], h[1] - sq[1][1] - 1);
		} else if (i == 2){
			limit = min(ub[2][2], h[2] - sq[2][1] - 1);	
			limit = min(limit, w[2] - sq[1][2] -1);
		} else if (i == 3) {
			limit = min(ub[3][2], h[3] - sq[3][1] - sq[3][2]);	
			limit = min(limit, w[2] - sq[1][2] - sq[2][2]);			
		}
	} else if(j == 3){
		if (i == 1){
			limit = min(ub[1][3], h[1] - sq[1][1] - sq[1][2]);
		} else if (i == 2){
			limit = min(ub[2][3], h[2] - sq[2][1] - sq[2][2]);
			limit = min(ub[2][3], w[3] - sq[1][3] - 1);
		} else if (i == 3){
			limit = min(ub[3][3], h[3] - sq[3][1] - sq[3][2]);
			limit = min(limit, w[3] - sq[3][1] - sq[3][2]);
		}
	}
	
	for(int k=1; k<=limit; k++){
		sq[i][j] = k;
		
		if(j == 3){
			i ++;
			j = 1;
		} else {
			j ++;
		}
		
		backtracking(i, j);
		
		if(j == 1){
			i--;
			j = 3;
		} else {
			j --;
		}
	}
}

int main() {
	cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
	
	h[1] = h1;
	h[2] = h2;
	h[3] = h3;
	w[1] = w1;
	w[2] = w2;
	w[3] = w3;
	
	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			ub[i][j] = min(h[i], w[j]) - 2;
		}
	}
	
	backtracking(1, 1);
	
	cout << counter << endl;

	return 0;
}
