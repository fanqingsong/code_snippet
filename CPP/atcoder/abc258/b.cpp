#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>

/*
https://atcoder.jp/contests/abc258/tasks/abc258_b
*/

int n;
char a[11][11];

int main() {
	cin >> n;

	char maxn = '0';

	map<char, vector<pair<int, int>>> indexset;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];

			if (maxn < a[i][j]){
				maxn = a[i][j];
			}

			indexset[a[i][j]].push_back(make_pair(i, j));
		}
	}

//	cout << maxn << endl;
//	cout << "-----" << endl;

	vector<pair<int, int>> d;
	d.push_back(make_pair(0, 1));
	d.push_back(make_pair(0, -1));
	d.push_back(make_pair(1, 1));
	d.push_back(make_pair(1, -1));
	d.push_back(make_pair(1, 0));
	d.push_back(make_pair(-1, 1));
	d.push_back(make_pair(-1, -1));
	d.push_back(make_pair(-1, 0));

	long long maxret = -1;

	vector<pair<int, int>> indexs = indexset[maxn];
	int indexs_size = indexs.size();
	for(int k=0; k<indexs_size; k++){
		int maxi = indexs[k].first;
		int maxj = indexs[k].second;

		int curx = maxi;
		int cury = maxj;

		int size = d.size();
		for(int i=0; i<size; i++){
			pair<int, int> oned = d[i];
			int dx = oned.first;
			int dy = oned.second;

			long long num = 0;

			for(int j=n-1; j>=0; j--){
				int digit = a[curx][cury] - '0';
				num += digit * pow(10, j);

//				cout << "digit = " << digit << endl;
//				cout << "num =" << num << endl;

				curx += dx;
				if (curx < 0){
					curx += n;
				}
				curx %= n;

				cury += dy;
				if (cury < 0){
					cury += n;
				}
				cury %= n;
			}

//			cout << "================" << endl;
//			cout << num << endl;

			if (maxret < num){
				maxret = num;
			}
		}
	}

	cout << maxret << endl;

	return 0;
}
