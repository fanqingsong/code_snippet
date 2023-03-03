#include <iomanip>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

/*
https://atcoder.jp/contests/abcxxx/tasks/abcxxx_d
*/

int n, m;

const long long maxn=1e3+11;
long long gra[maxn][maxn],is[maxn],dr[maxn],vis[maxn];


int main()
{
	cin >> n >> m;

	map<int, set<int> > edges;
	vector<int> indegree(n+1);

	vector<vector<int> > trips(m);

	for(int i=0; i<m; i++){
		int stops;
		cin >> stops;

		vector<int>& trip_i = trips[i];
		vector<bool> visited(n+1, false);

		for(int j=0; j<stops; j++){
			int stop;
			cin >> stop;

			trip_i.push_back(stop);

			visited[stop] = true;
		}

		for(int it=trip_i[0]; it<trip_i[stops-1]; it++){
//			cout << "one stop = " << it << endl;

			// in this trip, this stop visited, skip to next
			if (visited[it]){
				continue;
			}

			for(int k=0; k<stops; k++){
				int up_stop = trip_i[k];

				if(edges[it].count(up_stop) > 0){
					continue;
				}

				edges[it].insert(up_stop);

				indegree[up_stop]++;
			}
		}
	}

//	for(auto it: edges){
//		int now = it.first;
//		set<int>& nexts = it.second;
//
//		cout << "now=" << now << endl;
//		cout << "nexts:";
//		for(auto nit: nexts){
//			cout << nit << " ";
//		}
//		cout << endl;
//	}

//	queue<int> qq;
//	for(int i=1; i<=n; i++){
//		if(indegree[i] == 0 && outdegree[i] > 0){
//			qq.push(i);
//			level[i] = 1;
//		}
//	}
//
//	int max_level = 0;
//	while(!qq.empty()){
//		int now_stop = qq.front();
//		qq.pop();
//
//		int now_level = level[now_stop];
//
//		set<int>& nexts = edges[now_stop];
//		for(auto next_stop: nexts){
//			indegree[next_stop]--;
//
//			if (indegree[next_stop] == 0){
//				level[next_stop] = min(now_level+1, level[next_stop]);
//
//				max_level = max(max_level, level[next_stop]);
//
//				if (outdegree[next_stop] > 0){
//					qq.push(next_stop);
//				}
//			}
//		}
//	}

	int level = 0;
	vector<bool> vis(n+1, false);

	do{
		vector<int> stops;

		for(int i=1; i<=n; i++){
			if (indegree[i] == 0 && !vis[i]){
				stops.push_back(i);
				vis[i] = true;
			}
		}

//		cout << "stops.size() =" << stops.size() << endl;

		if (stops.size() == 0){
			break;
		}

		level++;

		for(int i=0; i<stops.size(); i++){
			for(auto next: edges[stops[i]]){
				indegree[next]--;
			}
		}
	}while(true);

	cout << level << endl;

    return 0;
}



