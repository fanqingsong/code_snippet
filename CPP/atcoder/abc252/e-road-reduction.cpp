// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>

/*
https://atcoder.jp/contests/abc252/tasks/abc252_e
https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
*/

int N, M;
map<int, map<int, int64_t>> graph;
map<int, map<int, int>> road_number;

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(vector<int64_t> &dist, set<int> &watchSet) {
	// Initialize min value
	int64_t min = INT64_MAX;
	int min_index = -1;

//	cout << "INT64_MAX = " << INT64_MAX << endl;

	set<int>::iterator itr;
	for (itr = watchSet.begin(); itr != watchSet.end(); itr++) {
		int index = *itr;
		if (dist[index] <= min) {
			min = dist[index], min_index = index;
		}
	}

//	cout << "min_index = " << min_index << endl;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(vector<int64_t> &dist, vector<bool> &road_used) {
//	cout << "Vertex \t Distance from Source" << endl;
//	for (int i = 0; i < N; i++)
//		cout << i << " \t\t" << dist[i] << endl;
//
//	cout << "Road used:" << endl;
	for (int i = 0; i < M; i++) {
		if (road_used[i] == true) {
			cout << i + 1  << " ";
		}
	}
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int src) {
	vector<int64_t> dist(N, INT64_MAX); // The output array. dist[i] will hold the shortest
	// distance from src to i

	// for every vertex, where it is from
	vector<int> prev(N, -1);

	// sptSet[i] will be true if vertex i is included in shortest
	set<int> sptSet;
	// path tree or shortest distance from src to i is finalized

	// for any node which is already with distance
	set<int> watchSet;

	vector<bool> road_used(M, false);

	// Distance of source vertex from itself is always 0
	dist[src] = 0;
	watchSet.insert(src);

	// Find shortest path for all vertices
	while (true) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, watchSet);
		if (u == -1) {
			break;
		}

		// if u is already in spt, skip
		if (sptSet.count(u) != 0) {
			continue;
		}

		// Mark the picked vertex as processed
		sptSet.insert(u);
		watchSet.erase(u);

		// mark road_used
		int prev_index = prev[u];
//		cout << "u =" << u << " prev_index=" << prev_index << endl;
		if (-1 != prev_index) {
			int road_index = road_number[prev_index][u];
//			cout << "road is been used. -- " << road_index << endl;
			road_used[road_index] = true;
		}

		// Update dist value of the adjacent vertices of the picked vertex.
		for (auto [v, w] : graph[u]) {

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (sptSet.count(v) == 0 && w && dist[u] != INT64_MAX
			        && dist[u] + w < dist[v]) {
				watchSet.insert(v);
				dist[v] = dist[u] + w;
				prev[v] = u;
			}
		}
	}

	// print the constructed distance array
	printSolution(dist, road_used);
}


// driver program to test above function
int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		/*
		graph index:
			row: 0->N-1
			column: 0->N-1
		road_number:
			value: 0 -> M-1
		*/
		graph[a - 1][b - 1] = c;
		graph[b - 1][a - 1] = c;
		road_number[a - 1][b - 1] = i;
		road_number[b - 1][a - 1] = i;
	}

	dijkstra(0);

	return 0;
}
