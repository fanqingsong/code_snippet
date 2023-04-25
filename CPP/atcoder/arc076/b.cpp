
// C++ program for the above approach

#include <bits/stdc++.h>
#include <iomanip>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

typedef long long LL;

// DSU data structure
// path compression + rank by union
class DSU {
	LL* parent;
	LL* rank;

public:
	DSU(LL n)
	{
		parent = new LL[n];
		rank = new LL[n];

		for (LL i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find function
	LL find(LL i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}

	// Union function
	void unite(LL x, LL y)
	{
		LL s1 = find(x);
		LL s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
			}
			else if (rank[s1] > rank[s2]) {
				parent[s2] = s1;
			}
			else {
				parent[s2] = s1;
				rank[s1] += 1;
			}
		}
	}
};

class Graph {
	vector<vector<LL> > edgelist;
	LL V;

public:
	Graph(LL V) { this->V = V; }

	// Function to add edge in a graph
	void addEdge(LL x, LL y, LL w)
	{
		edgelist.push_back({ w, x, y });
	}

	LL kruskals_mst()
	{
		// Sort all edges
		sort(edgelist.begin(), edgelist.end());

		// Initialize the DSU
		DSU s(V);
		LL ans = 0;
//		cout << "Following are the edges in the "
//				"constructed MST"
//			<< endl;
		for (auto edge : edgelist) {
			LL w = edge[0];
			LL x = edge[1];
			LL y = edge[2];

			// Take this edge in MST if it does
			// not forms a cycle
			if (s.find(x) != s.find(y)) {
				s.unite(x, y);
				ans += w;
//				cout << x << " -- " << y << " == " << w
//					<< endl;
			}
		}
//		cout << "Minimum Cost Spanning Tree: " << ans;
		
        return ans;
	}
};

struct point {long long id, x, y;};

LL llabs(LL a)
{
    return a >= 0? a: -a;
}

bool cmp_x(struct point a, struct point b)
{
    return a.x < b.x;
}

bool cmp_y(struct point a, struct point b)
{
    return a.y < b.y;
}

LL n;
vector<struct point> pts;


// Driver code
int main()
{
	cin >> n;
	
	for(LL i=1; i<=n; i++){
		LL x, y;
		
		cin >> x >> y;
		
		struct point pt;
		pt.id = i;
		pt.x = x;
		pt.y = y;
		
		pts.push_back(pt);
	}

	Graph g(n+10);
	
	sort(pts.begin(), pts.end(), cmp_x);
    for (LL i = 0; i < n - 1; i++) {
        LL u = pts[i].id;
        LL v = pts[i + 1].id;
        LL w = pts[i + 1].x - pts[i].x;
        w = llabs(w);
        
        g.addEdge(u, v, w);
    }
	
	sort(pts.begin(), pts.end(), cmp_y);
    for (LL i = 0; i < n - 1; i++) {
        LL u = pts[i].id;
        LL v = pts[i + 1].id;
        LL w = pts[i + 1].y - pts[i].y;
        w = llabs(w);

        g.addEdge(u, v, w);
    }

	LL cost = g.kruskals_mst();

	cout << cost << endl;

	return 0;
}



