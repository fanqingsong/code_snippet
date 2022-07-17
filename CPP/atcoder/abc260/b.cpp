
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
https://atcoder.jp/contests/abc260/tasks/abc260_b
*/

int main()
{
	int n, x, y, z;
	int a[1004];
	int b[1004];
	bool vis[1004];
	
	vector<int> ad;

	cin >> n >> x >> y >> z;
	
	REP(i, n){
		cin >> a[i+1];
		vis[i+1] = false;
	}

	REP(i, n){
		cin >> b[i+1];
		vis[i+1] = false;
	}

	while(x>0){
		int most = -1;
		int index = -1;

		REP(i, n){
			if (vis[i+1] == true){
				continue;
			}

			int ai = a[i+1];
			if(ai > most){
				most = ai;
				index = i+1;
			}

//			cout << "ai = " << a[i+1] << endl;
//			cout << "most = " << most << endl;
//			cout << "index = " << index << endl;
		}

		if(most > -1){
//			cout << "x add index" << index << endl;
			ad.push_back(index);
			vis[index] = true;
			x--;
		} else{
			break;
		}
	}

	while(y>0){
		int most = -1;
		int index = -1;

		REP(i, n){
			if (vis[i+1] == true){
				continue;
			}

			int bi = b[i+1];
			if(bi > most){
				most = bi;
				index = i+1;
			}
		}

		if(most > -1){
//			cout << "y add index" << index << endl;
			ad.push_back(index);
			vis[index] = true;
			y--;
		} else{
			break;
		}
	}

	while(z>0){
		int most = -1;
		int index = -1;

		REP(i, n){
			if (vis[i+1] == true){
				continue;
			}

			int abi = a[i+1] + b[i+1];
			if(abi > most){
				most = abi;
				index = i+1;
			}
		}

		if(most > -1){
//			cout << "z add index" << index << endl;
			ad.push_back(index);
			vis[index] = true;
			z--;
		} else{
			break;
		}
	}
	
	sort(ad.begin(), ad.end());

//	cout << "-------------------" << endl;
	int size = ad.size();
	REP(i, size){
		cout << ad[i] << endl;
	}
	
    return 0;
}



