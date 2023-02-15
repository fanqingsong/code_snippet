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

int h, w, k;
vector<vector<int>> s(16, vector<int>(1006, 0));
//int s[16][1006];

// prefix sum
vector<vector<int>> ps(16, vector<int>(1006, 0));
//int ps[16][1006];

vector<int> hcuts;
vector<int> hlines;
vector<int> vlines;

int main()
{
	cin >> h >> w >> k;
	
//	if(h>15 || w>105){
//		return 0;
//	}
	
	REP(i, h){
		int hi = i+1;
		
		REP(j, w){
			int wj = j+1;
			
			char one;
			cin >> one;
			
			s[hi][wj] = (one=='1'?1:0);
//			cout << s[hi][wj];
			
			ps[hi][wj] = s[hi][wj] + ps[hi-1][wj] + ps[hi][wj-1] - ps[hi-1][wj-1];
		}
//		cout << endl;
	}
	
	if (ps[h][w] <= k){
		cout << 0 << endl;
		return 0;
	}
	
	int mincuts = (h-1) * (w-1);
	
	// horizontally split
	int rc = pow(2, h-1)-1;
	for(int i=0; i<=rc; i++){
//		cout << "----------- combination i = " << i << " ----------" << endl;
		int num=i;
		// figure out cuts of horizons

		hcuts.clear();
		for(int j=1;num>0; j++){
//			cout << "j = " << j << endl;
//			cout << "i&j == j ===> " << ((i&j) == j) << endl;
			if(num%2==1){
				hcuts.push_back(j);
			}
			num/=2;
		}

//
//		cout << "------ hcuts: combination individual cases --------" << endl;
//		REP(j, hcuts.size()){
//			cout << hcuts[j] << " ";
//		}
//		cout << endl;

		/* hlines: 0 1 3
		------ 0
		1 2 3
		------ 1
		4 5 6
		7 8 9
		----- 3
		*/
		hlines.clear();
		hlines.push_back(0);
		REP(j, hcuts.size()){
			hlines.push_back(hcuts[j]);
		}
		hlines.push_back(h);
//		
//		cout << "--------- hlines --------" << endl;
//		REP(j, hlines.size()){
//			cout << hlines[j] << " ";
//		}
//		cout << endl;
		
		// vertically split
		/*
		vlines: 0 1 3
		|1|2 3|
		|4|5 6|
		|7|8 9|
		0 1   3
		*/

		vlines.clear();
		vlines.push_back(0);
		bool hcuts_abort = false;
		while(true){
			int vline_prev = vlines[vlines.size()-1];
			int vline_now = vline_prev+1;

//			cout << "--> vline_prev=" << vline_prev << endl;
//			cout << "--> vline_now=" << vline_now << endl;

			while(vline_now<=w){
//				cout << "try vline_now, it value=" << vline_now << endl;
				int hlines_len = hlines.size();
				/*
				--------- 0
				|1|2 3|
				--------- 1
				|4|5 6|
				|7|8 9|
				--------- 3
				0 1   3
				*/
				bool greatk = false;
				for(int i=1; i<hlines_len; i++){
					int hline_prev = hlines[i-1];
					int hline_now = hlines[i];

//					cout << "hline_prev=" << hline_prev << endl;
//					cout << "hline_now=" << hline_now << endl;
					
					int rectsum = ps[hline_now][vline_now]
						- ps[hline_now][vline_prev]
						- ps[hline_prev][vline_now]
						+ ps[hline_prev][vline_prev];
						
//					cout << "rectsum = " << rectsum << endl;
					
					if (rectsum>k){
						// vertially first try is failed by move one step from vline_prev
						// it means some vertial segment has greater white blocks than k in one first try
						if(vline_now == vline_prev+1){
							hcuts_abort = true;
						} else {
							vlines.push_back(vline_now-1);
						}

						greatk = true;
						break;
					}
				}
				
				if(greatk){
					break;
				}

				vline_now++;
			}
			
			// for last vertical segment, no need to cut
			if(vline_now > w){
				break;
			}
			
			if(hcuts_abort){
				break;
			}
		}
		vlines.push_back(w);
		
		if(hcuts_abort){
//			cout << "----------- combination i = " << i << " aborted ----------" << endl;
			continue;
		}
//		
//		cout << "----------- combination i = " << i << " met, its solution ----------" << endl;
//
//		cout << "--------- hlines --------" << endl;
//		REP(j, hlines.size()){
//			cout << hlines[j] << " ";
//		}
//		cout << endl;
//
//		cout << "--------- vlines --------" << endl;
//		REP(j, vlines.size()){
//			cout << vlines[j] << " ";
//		}
//		cout << endl;

		int cuts_num = hlines.size() - 2 + vlines.size() - 2;
//		cout << "----- current combination cuts ------";
//		cout << cuts_num << endl;

		mincuts = min(mincuts, cuts_num);
	}

	cout << mincuts << endl;

    return 0;
}



