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
map<char, set<char>> mp;
map<char, int> indegree;
vector<char> orders;


int topo(){
//	cout << "--------- call topo ------------" << endl;
	
	map<char, int> indegree_c = indegree;
	
	/*
	for presumption of topological order existence
	such as
	a1 -> a2 -> ... -> an
	there are n times to do getting zero indegree node
	*/
	queue<char> qq;
	for(auto it: indegree_c){
		char one = it.first;
		int dg = it.second;
		
//		cout << "char=" << one << endl;
//		cout << "dg=" << dg << endl;
		
		if (dg == 0){
			qq.push(one);
		}
	}
	
	while(!qq.empty()){
		// at any time, there should be one element in queue
		if (qq.size() == 1){
			// well status
		} else if (qq.size() > 1){
			// there are undetermined order elments
//			cout << "there are undetermined order elments" << endl;
			return -1;
		}
		
		char one = qq.front();
		qq.pop();
		
		indegree_c[one] = -1;
		
		orders.push_back(one);
		
		for(auto next: mp[one]){
			indegree_c[next]--;
			
			if (indegree_c[next] == 0){
				qq.push(next);
			}
		}
	}

	// determined order
	if (orders.size() == n){
//		cout << "determined order" << endl;
		return 0;
	}
	
	// cycled
	for(auto it: indegree_c){
		char one = it.first;
		int dg = it.second;
		
//		cout << "char = "<< one << ": degree="<< dg << endl;

		if (dg > 0){
//			cout << "cycled" << endl;
			return 1;
		}
	}
	
//	cout << "last return" << endl;
	return -1;
}

int main()
{
	while(cin >> n >> m){
		if(!n && !m){
			break;
		}
		
		mp.clear();
		indegree.clear();
		orders.clear();
		
		for(char a='A'; a<='A'+n-1; a++){
			mp[a] = set<char>();
			indegree[a] = 0;
		}
		
		bool fixed = false;
		
		for(int i=1; i<=m; i++){
			string input;
			cin >> input;

			// already fixed, so no more action needed, only read the left input
			if (fixed){
				continue;
			}

			char first = input[0];
			char second = input[2];

			if(mp[first].count(second) == 0){
				mp[first].insert(second);
				indegree[second]++;
			}

			int res = topo();
			
			// cycled
			if(res == 1){
				cout << "Inconsistency found after "<<i<<" relations." << endl;
				fixed = true;
			// ordered
			} else if (res == 0) {
				cout << "Sorted sequence determined after "<< i <<" relations: " << endl;
				for(int j=0; j<orders.size(); j++){
					cout << orders[j];
				}
				cout << endl;
				
				fixed = true;
			}
		}
		
		// no ordered
		if(!fixed){
			cout << "Sorted sequence cannot be determined." << endl;
		}
	}

    return 0;
}



