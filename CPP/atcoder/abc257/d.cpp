#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <queue>

/*
https://atcoder.jp/contests/abc257/tasks/abc257_d
*/

bool check(int s);
void calc_dist();


int n;

int x[202];
int y[202];
int p[202];

int dist[202][202];

int x_min = 1e9;
int x_max = -1e9;
int y_min = 1e9;
int y_max = -1e9;

int p_max = 0;


int main() {
	cin >> n;
	
	for(int i=1; i<=n; i++){
		cin >> x[i];
		cin >> y[i];
		cin >> p[i];

		if(x_min > x[i]){
			x_min = x[i];
		}
		
		if (x_max < x[i]){
			x_max = x[i];
		}
		
		if (y_min > y[i]){
			y_min = y[i];
		}
		
		if (y_max < y[i]){
			y_max = y[i];
		}
		
		if (p_max < p[i]){
			p_max = p[i];
		}
	}

	calc_dist();

	int x_range_len = x_max - x_min;
	int y_range_len = y_max - y_min;
	int max_range_len = max(x_range_len, y_range_len);
	int s_max = max_range_len / p_max + 2;
	int s_min = 1;

	int s_goal;
	while(s_min < s_max){
//		cout << "s_max = " << s_max << endl;
//		cout << "s_min = " << s_min << endl;
		
		int s_mid = (s_max + s_min) / 2;
//		cout << "s_mid = " << s_mid << endl;
		
		bool isok = check(s_mid);
//		cout << "isok = " << isok << endl;
		if (isok){
			s_goal = s_mid;
			s_max = s_mid;
		} else {
			s_min = s_mid+1;
		}
	}

	cout << s_goal << endl;

	return 0;
}

void calc_dist(){
	for(int i=1; i<=n; i++){
		dist[i][i] = 0;
	}

	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			int one_dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			dist[i][j] = one_dist;
			dist[j][i] = one_dist;
		}
	}
}

bool check(int s) {
	vector<vector<int>> covered(n+1);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if (i == j){
				continue;
			}
			
			int cover_len = p[i] * s;
			
			if (cover_len >= dist[i][j]){
				covered[i].push_back(j);
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		set<int> closed;
		queue<int> opened;
		
		opened.push(i);
		while(!opened.empty()){
			int item = opened.front();
			opened.pop();
			
			closed.insert(item);

			vector<int> adjs = covered[item];
			int size = adjs.size();
			for(int i=0; i<size; i++){
				int adj_item = adjs[i];
				
				if (closed.count(adj_item) > 0){
					continue;
				}
				
				opened.push(adj_item);
			}
		}
		
		if (closed.size() == n){
			return true;
		}
	}
	
	return false;
}


