
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

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
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
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v¡¯s list.
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

/******************************** GRAPH END ***************************************/

/*
https://atcoder.jp/contests/abc259/tasks/abc259_d
*/

const int N = 1005;
const int SPACE = 20010;
int n, x, y;
int xsteps[N];
int ysteps[N];

int xindex = 0;
int yindex = 0;

map<int, map<int, bool>> fx;
map<int, map<int, bool>> fy;


int main()
{
	cin >> n >> x >> y;

	for(int i=0; i<n; i++){
		if (i % 2 == 0){
			cin >> xsteps[++xindex];
		} else {
			cin >> ysteps[++yindex];
		}
	}

	// after step one in x direction
	// get offset xsteps[1];
	fx[1][xsteps[1]] = true;

	// initial status in y direction
	// get offset 0;
	fy[0][0] = true;
	
	// skip step one in x direction
	for(int i=2; i<=xindex; i++){
		int xi = xsteps[i];
		
		// based on i-1 status, move xi
		// calculate i status
		map<int, bool> fx_prev = fx[i-1];
		map<int, bool>::iterator it;
		for(it=fx_prev.begin(); it!=fx_prev.end(); it++){
			int j = it->first;

			int left = j - xi;
			int right = j + xi;

			fx[i][left] = true;
			fx[i][right] = true;
		}
	}

	for(int i=1; i<=yindex; i++){
		int yi = ysteps[i];
//		cout << "i=" << i << " yi=" << yi << endl;

		// based on i-1 status, move yi
		// calculate i status
		map<int, bool> fy_prev = fy[i-1];
		map<int, bool>::iterator it;
		for(it=fy_prev.begin(); it!=fy_prev.end(); it++){
			int j = it->first;

			int up = j + yi;
			int down = j - yi;

			fy[i][down] = true;
			fy[i][up] = true;
		}
	}

//	cout << "fx[xindex][x] = " << fx[xindex][x] << endl;
//	cout << "fy[yindex][y] = " << fy[yindex][y] << endl;

//	for(int i=0; i<10000; i++){
//		if (fy[xindex][i] == false){
//			continue;
//		}
//
//		cout << "!!fy[xindex][" << i << "] = " << fy[xindex][i] << endl;
//	}

	if (fx[xindex][x] && fy[yindex][y]){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

    return 0;
}





