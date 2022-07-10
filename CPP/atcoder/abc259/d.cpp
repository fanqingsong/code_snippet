
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <stack>

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

//double EPS = 1e-9;
double EPS = 1e-3;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#ifdef TESTING
#define DEBUG fprintf(stderr, "====TESTING====\n")
#define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG
#define VALUE(x)
#define debug(...)
#endif

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)

/******************************** COMMON FUNC START ***************************************/

inline string IntToString(LL a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}

inline LL StringToInt(string a)
{
    char x[100];
    LL res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}

inline string GetString(void)
{
    char x[1000005];
    scanf("%s", x);
    string s = x;
    return s;
}

inline string uppercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'a' && s[i] <= 'z')
        s[i] = s[i] - 'a' + 'A';
    return s;
}

inline string lowercase(string s)
{
    int n = SIZE(s);
    REP(i, n)
    if (s[i] >= 'A' && s[i] <= 'Z')
        s[i] = s[i] - 'A' + 'a';
    return s;
}

inline void OPEN(string s)
{
#ifndef TESTING
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
#endif
}

/******************************** COMMON FUNC END ***************************************/

/******************************** GRAPH START ***************************************/
// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    bool DFS(int s, int t);
};

void Graph::addEdge(int v, int w)
{
//	cout << "connect v=" << v << "to w=" << w << endl;
    adj[v].push_back(w); // Add w to v¡¯s list.
}

bool Graph::DFS(int s, int t)
{
    // Mark the current node as visited and
    // print it
    visited[s] = true;
//    cout << "visit " << s << " ";

	if (s == t){
//		cout << "found!" << endl;
		return true;
	}

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i){
        if (!visited[*i]){
        	bool ret = DFS(*i, t);
			if (ret == true) {
				return true;
			}
		}
	}

	return false;
}

/******************************** GRAPH END ***************************************/

/*
https://atcoder.jp/contests/abc259/tasks/abc259_d
*/


class Circle{
	public:
		LL x;
		LL y;
		LL r;
		
		Circle(){
			//
		}
		
		Circle(LL xi, LL yi, LL ri){
			x = xi;
			y = yi;
			r = ri;
		}
		
		bool is_connected(Circle cc){
			LL xi = cc.x;
			LL yi = cc.y;
			LL ri = cc.r;
			
			LL dist2 = SQR(x - xi) + SQR(y - yi);
			if (dist2 <= (r + ri)*(r + ri) && dist2 >=(r - ri)*(r - ri)) {
				return true;
			}
			
			return false;
		}
		
		bool is_on_side(LL xi, LL yi){
			LL dist2 = SQR(x - xi) + SQR(y - yi);
			
			if (dist2 == r*r){
				return true;
			}
			
			return false;
		}
};


int main()
{
	int n;
	LL sx, sy, tx, ty;
	vector<Circle> circles;
	Graph connects;

	cin >> n;
	cin >> sx >> sy >> tx >> ty;
	
	int si = -1, ti = -1;
	
	REP(i, n){
		Circle cc;
		cin >> cc.x;
		cin >> cc.y;
		cin >> cc.r;

		int size = circles.size();
		REP(j, size){
			Circle cc2 = circles[j];
			if (cc.is_connected(cc2)){
				connects.addEdge(i, j);
				connects.addEdge(j, i);
			}
		}

		circles.push_back(cc);
		
		if(si==-1 && cc.is_on_side(sx, sy)){
			si = i;
		}

		if(ti==-1 && cc.is_on_side(tx, ty)){
			ti = i;
		}
	}

	if (si == -1 || ti == -1){
//		cout << "illegal data." << endl;
		return 0;
	}
	
//	cout << "si =" << si << " ti=" << ti << endl;
	
	bool ret = connects.DFS(si, ti);
	
	if (ret){
		cout << "Yes" << endl;
		return 0;
	}
	
	cout << "No" << endl;
	
    return 0;
}



