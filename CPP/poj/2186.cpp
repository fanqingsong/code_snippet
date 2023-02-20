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

LL quick_pow(LL x,LL n,LL m){
	LL res = 1;
	while(n > 0){
		if(n & 1)	res = res * x % m;
		x = x * x % m;
		n >>= 1;//相当于n=n/2.详情请参考位移运算符。
	}

	return res;
}

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
    adj[v].push_back(w); // Add w to v’s list.
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
https://atcoder.jp/contests/abcxxx/tasks/abcxxx_d
*/

int n, m;

map<int, map<int, bool> > g, rg;

// label node as visited
vector<bool> vis;

// pv : post visit
// store node by post visit order
stack<int> pv;

// color node to indicate one component
map<int, int> color;

// the order of strongly connected component
int sscCnt = 0;

map<int, set<int> > ssc;

void dfs(int i){
	vis[i] = true;
	
	for(auto it: g[i]){
		int next = it.first;
		
		if (!vis[next]){
			dfs(next);
		}
	}
	
	pv.push(i);
}

void rdfs(int i){
	color[i] = sscCnt;
	
	ssc[sscCnt].insert(i);
	
	for(auto it: rg[i]){
		int next = it.first;
		
		if (!color[next]){
			rdfs(next);
		}
	}
}

int main()
{
	cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int u, v;
		cin >> u >> v;
		
		g[u][v] = true;
		rg[v][u] = true;
	}

//	cout << "after g rg done ---" << endl;

	// index from 1 to align with node numbers: 1 ~ n
	vis.push_back(false);
	for(int i=1; i<=n; i++){
		vis.push_back(false);
	}

//	cout << "after g rg done ---" << endl;

	// visit on g to get pv
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}

	// visit on rg to get sscCnt
	while(!pv.empty()){
		int top = pv.top();
		pv.pop();
		
		if (!color[top]){
			++sscCnt;
			
			rdfs(top);
		}
	}

//	for(auto it: ssc){
//		int sscIndex = it.first;
//		set<int>& nodes = it.second;
//		
//		cout << "ssc" << sscIndex << ":";
//		for(auto nit: nodes){
//			cout << nit << " ";
//		}
//		cout << endl;
//	}

	int indegree[sscCnt+1];
	int outdegree[sscCnt+1];
	memset(indegree, 0, sizeof(indegree));
	memset(outdegree, 0, sizeof(outdegree));

	for(auto uit: g){
		int u = uit.first;
		int uc = color[u];
		
		for(auto vit: g[u]){
			int v = vit.first;
			int vc = color[v];
			
			outdegree[uc]++;
			indegree[vc]++;
		}
	}
	
	for(int i=1; i<=sscCnt; i++){
		if(outdegree[i] == 0){
			cout << ssc[i].size() << endl;
			break;
		}
	}

    return 0;
}



