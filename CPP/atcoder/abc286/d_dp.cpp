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
https://atcoder.jp/contests/abcxxx/tasks/abcxxx_d
*/

const int N = 50;
const int X = 1e4;

int n, x;

/*
ai -- a yuan of one coin
bi -- b coins of a yuan
*/
int a[60];
int b[60];

/*
dp[i][j]:
for j yuan,
find if it is possible to get j yuan
with the first i coins.

i = 1 --> N
j = 1 --> X

dp[i][j] =
	dp[i-1][j]
	| dp[i-1][j-ai]
	| dp[i-1][j-2ai]
	...
	| dp[i-1][j-bi*ai]
	
check if dp[n][x] == true ?
*/

bool dp[N+1][X+1];

int main()
{
	cin >> n >> x;
	for(int i=1; i<=n; i++){
		cin >> a[i] >> b[i];
	}

	/*
	for 0 yuan
	if no coins are selected,
	0 yuan is meeted.
	there is one way to make it.
	*/
	dp[0][0] = true;

	/*
	for 0 yuan,
	as of the first i coins
	there are one way to get 0 yuan
	ie, no selection of any coin.
	*/
	for(int i=1; i<=N; i++){
		dp[i][0] = true;
	}

	/*
	for any j yuan
	if no one coin is selected
	there is no way to get j yuan.
	*/
	for(int j=1; j<=X; j++){
		dp[0][j] = false;
	}
	
	/*
	i = 1 --> n
	j = 1 --> x
	
	dp[i][j] =
		dp[i-1][j]
		| dp[i-1][j-ai]
		| dp[i-1][j-2ai]
		...
		| dp[i-1][j-bi*ai]
	*/
	for(int i=1; i<=n; i++){
		int ai = a[i];
		int bi = b[i];
		
		for(int j=1; j<=x; j++){
			dp[i][j] = 0;
			
			for(int k=0; k<=bi&&k*ai<=j; k++){
				dp[i][j] |= dp[i-1][j-k*ai];
			}
		}
	}

	if (dp[n][x] > 0){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

    return 0;
}



