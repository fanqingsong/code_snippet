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
map<int, map<int, long long>> graph;
map<int, map<int, int>> road_number;


// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(long long dist[], bool sptSet[], int V) {

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(long long dist[], int V, bool road_used[]) {
//	cout << "Vertex \t Distance from Source" << endl;
//	for (int i = 0; i < V; i++)
//		cout << i << " \t\t" << dist[i] << endl;

//	cout << "Road used:" << endl;
	for (int i = 0; i < M; i++) {
		if (road_used[i] == true) {
			cout << i + 1  << " ";
		}
	}
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int V, int src) {
	long long dist[V]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	// for every vertex, where it is from
	int prev[V];

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	bool road_used[M];

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false, prev[i] = -1;

	for (int i = 0; i < M; i++) {
		road_used[i] = false;
	}

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V ; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet, V);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// mark road_used
		int prev_index = prev[u];
		//cout << "u =" << u << " prev_index=" << prev_index << endl;
		if (-1 != prev_index) {
			int road_index = road_number[prev_index][u];
			//cout << "road is been used. -- " << road_index << endl;
			road_used[road_index] = true;
		}

		// Update dist value of the adjacent vertices of the picked vertex.
		for (auto [v, w] : graph[u]) {

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && w && dist[u] != INT_MAX
			        && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				prev[v] = u;
			}
		}

//		for (int v = 0; v < V; v++)
//
//			// Update dist[v] only if is not in sptSet, there is an edge from
//			// u to v, and total weight of path from src to v through u is
//			// smaller than current value of dist[v]
//			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
//			        && dist[u] + graph[u][v] < dist[v]) {
//				dist[v] = dist[u] + graph[u][v];
//				prev[v] = u;
//			}
	}

	// print the constructed distance array
	printSolution(dist, V, road_used);
}


// driver program to test above function
int main() {
	/* Let us create the example graph discussed above */
	/*
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
		{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
		{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
		{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
		{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
		{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
		{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
		{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
		{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};*/

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

	dijkstra(N, 0);

	return 0;
}

// This code is contributed by shivanisinghss2110
