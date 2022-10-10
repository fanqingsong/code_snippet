
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
    stack<int> path;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v to w
    bool DFS(int v, int w);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v¡¯s list.
}

bool Graph::DFS(int v, int w)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    path.push(v);
    cout << v << " ";

	if (w == v){
		cout << "found" << endl;
		return true;
	}

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
		int next = *i;

        if (!visited[next]){
            bool found = DFS(next, w);
            if (found == true){
            	return true;
			} else {
				path.pop();
			}
		}
	}
}

/******************************** GRAPH END ***************************************/

/*
https://atcoder.jp/contests/abc259/tasks/abc259_d
*/

class NODE{
public:
	int v;
	int i;
		
	NODE(int _v, int _i){
		v = _v;
		i = _i;
	}
};

int n, w;

vector<NODE> a;
vector<NODE> used;
vector<int> lefta;

bool cmp(NODE a, NODE b){
	if (a.v > b.v){
		return true;
	}
	
	return false;
}


bool cmpi(NODE a, NODE b){
	if (a.i < b.i){
		return true;
	}

	return false;
}

int main()
{
	cin >> n >> w;
	
	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;
		
		NODE one(temp, i);
		a.push_back(one);
	}

	sort(a.begin(), a.end(), cmp);

//	for(int i=0; i<n; i++){
//		NODE one = a[i];
//		cout << one.v << endl;
//		cout << one.i << endl;
//	}

	int halfsum = 0;
	for(int i=0; i<n; i++){
		int one_av = a[i].v;
		int one_ai = a[i].i;
		
//		cout << "one_av=" << one_av << endl;
//		cout << "one_ai=" << one_ai << endl;
		
		int half = 0;
		if (one_av % 2 == 0){
			half = one_av / 2;
		} else {
			half = one_av / 2 + 1;
		}

		NODE one_used(half, one_ai);
		used.push_back(one_used);
		
		halfsum += half;
		lefta.push_back(one_av - half);
	}

//	cout << halfsum << endl;

	if (halfsum > w){
		cout << -1 << endl;
		return 0;
	}

	int leftw = w - halfsum;
	for(int i=0; i<n; i++){
		if (leftw >= lefta[i]){
			leftw -= lefta[i];
			used[i].v = a[i].v;
		} else {
			used[i].v += leftw;
			leftw = 0;
			break;
		}
	}

	sort(used.begin(), used.end(), cmpi);

	for(int i=0; i<n; i++){
		cout << used[i].v << " ";
	}

    return 0;
}



