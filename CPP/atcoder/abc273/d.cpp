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

int h,w;
int rs, cs;
int n, q;
map<int, vector<int>> xblocks;
map<int, vector<int>> yblocks;

int main()
{
	cin >> h >> w;
	cin >> rs >> cs;
	cin >> n;
	
	/*
		store x-direction blocks, i.e. ci
		store y-direction blocks, i.e. ri
	*/
	for(int i=0; i<n; i++){
		int ri, ci;
		cin >> ri >> ci;
		vector<int>& tempx = xblocks[ri];
		tempx.push_back(ci);
		
		vector<int>& tempy = yblocks[ci];
		tempy.push_back(ri);
	}

	/*
	sort all blocks of each x-directions
	*/
	map<int, vector<int>>::iterator it;
	for(it=xblocks.begin(); it!=xblocks.end(); it++){
		vector<int>& block_list = it->second;
		
		sort(block_list.begin(), block_list.end());
	}

	/*
	sort all blocks of each y-directions
	*/
	for(it=yblocks.begin(); it!=yblocks.end(); it++){
		vector<int>& block_list = it->second;

		sort(block_list.begin(), block_list.end());
	}

	cin >> q;
	// ri ci are position where T is moving
	int ri = rs;
	int ci = cs;
	for(int i=0; i<q; i++){
		string di;
		int li;
		cin >> di >> li;
		
		// horizontal blocks
		vector<int>& hb = xblocks[ri];

		// vertical blocks
		vector<int>& vb = yblocks[ci];

		vector<int>::iterator low, up;
		
		if (di == "L"){
			// no block in that row
			if(hb.size() == 0){
//				cout << "ci = " << ci << endl;
//				cout << "li = " << li << endl;
				int pos = ci - li;
				ci = pos>0?pos:1;
				cout << ri << " " << ci << endl;
				continue;
			}
			
			int first = hb[0];
			int last = hb[hb.size()-1];
			if (ci < first){
				int pos = ci - li;
				ci = pos>0?pos:1;
				cout << ri << " " << ci << endl;
				continue;
			}
			
			if (ci > last){
				int pos = ci - li;
				ci = pos>last?pos:(last+1);

				cout << ri << " " << ci << endl;
				continue;
			}
			
			up = upper_bound(hb.begin(), hb.end(), ci);
			int upindex = up - hb.begin();
			int base = hb[upindex-1];
			int pos = ci - li;
			ci = pos>base?pos:(base+1);
			
			cout << ri << " " << ci << endl;
		} else if (di == "R") {
			// no block in that row
			if(hb.size() == 0){
				int pos = ci + li;
				ci = pos<=w?pos:w;
				cout << ri << " " << ci << endl;
				continue;
			}

			int first = hb[0];
			int last = hb[hb.size()-1];
			if (ci < first){
				int pos = ci + li;
				ci = pos<first?pos:(first-1);

				cout << ri << " " << ci << endl;
				continue;
			}

			if (ci > last){
				int pos = ci + li;
				ci = pos<=w?pos:w;

				cout << ri << " " << ci << endl;
				continue;
			}

			up = upper_bound(hb.begin(), hb.end(), ci);
			int upindex = up - hb.begin();
			int top = hb[upindex];
			int pos = ci + li;
			ci = pos<top?pos:top-1;

			cout << ri << " " << ci << endl;
		} else if (di == "U") {
			// no block in that column
			if(vb.size() == 0){
				int pos = ri - li;
				ri = pos>0?pos:1;
				cout << ri << " " << ci << endl;
				continue;
			}

			int first = vb[0];
			int last = vb[vb.size()-1];
			if (ri < first){
				int pos = ri - li;
				ri = pos>0?pos:1;

				cout << ri << " " << ci << endl;
				continue;
			}

			if (ri > last){
//				cout << "ri = " << ri << endl;
//				cout << "li = " << li << endl;
//				cout << "last = " << last << endl;
				
				int pos = ri - li;
				ri = pos>last?pos:(last+1);

				cout << ri << " " << ci << endl;
				continue;
			}

			up = upper_bound(vb.begin(), vb.end(), ri);
			int upindex = up - vb.begin();

			int top = vb[upindex-1];
			int pos = ri - li;
			ri = pos>top?pos:(top+1);
			
			cout << ri << " " << ci << endl;
		} else if (di == "D") {
			// no block in that column
			if(vb.size() == 0){
				int pos = ri + li;
				ri = pos<=h?pos:h;

				cout << ri << " " << ci << endl;
				continue;
			}

			int first = vb[0];
			int last = vb[vb.size()-1];
			if (ri < first){
				int pos = ri + li;
				ri = pos<first?pos:(first-1);

				cout << ri << " " << ci << endl;
				continue;
			}

			if (ri > last){
				int pos = ri + li;
				ri = pos<=h?pos:h;

				cout << ri << " " << ci << endl;
				continue;
			}

			up = upper_bound(vb.begin(), vb.end(), ri);
			int upindex = up - vb.begin();

			int top = vb[upindex];
			int pos = ri + li;
			ri = pos<top?pos:(top-1);

			cout << ri << " " << ci << endl;
		}
	}

    return 0;
}



