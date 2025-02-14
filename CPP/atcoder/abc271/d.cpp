
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
    deque<int> path;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v to w
    bool DFS(int v, int w);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v��s list.
    adj[w].push_back(v);
}

bool Graph::DFS(int v, int w)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    path.push_back(v);
//    cout << v << " ";

	if (w == v){
//		cout << "found" << endl;
		return true;
	}

    // Recur for all the vertices adjacent
    // to this vertex
//    cout << "before for..." << endl;
    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); it++)
    {
		int next = *it;
//		cout << "next=" << next << endl;

        if (!visited[next]){
            bool found = DFS(next, w);
            if (found == true){
            	return true;
			} else {
				path.pop_back();
			}
		}
	}

	return false;
}

/******************************** GRAPH END ***************************************/

/*
https://atcoder.jp/contests/abc259/tasks/abc259_d
*/
bool f[101][10000];


int main(){
	int n,m,a[101],b[101];
	cin>>n>>m;

	f[0][0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<=m;j++){
			if(j>=a[i])f[i][j]|=f[i-1][j-a[i]];
			if(j>=b[i])f[i][j]|=f[i-1][j-b[i]];
		}
	}
	if(f[n][m]==1){
		cout<<"Yes"<<endl;
		int cur=m;
		string s="";
		
		for(int i=n;i>0;i--){
			cout << "i=" << i << endl;
			
			if(cur>=a[i]&&f[i-1][cur-a[i]]==1){
				cur-=a[i];
				s+='H';
				cout << s << endl;
			} else if(cur>=b[i]&&f[i-1][cur-b[i]]==1){
				cur-=b[i];
				s+='T';
				cout << s << endl;
			} else {
				cout << "else" << endl;
			}
		}
		
		cout << s << endl;
		
		reverse(s.begin(),s.end());
		cout<<s<<endl;
	}else{
		cout<<"No"<<endl;
	}
}



