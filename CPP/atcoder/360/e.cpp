//
//                       _oo0oo_
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//
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

typedef long long ll;

const ll m = 998244353;

ll fp(ll x, ll p){
	ll qp = x;
	ll ret = 1;
	
	while(p){
		if (p&1) ret = ret * qp % m;
		
		qp = qp * qp % m;
		
		p >>= 1;
	}
	
	return ret;
}

ll inv(ll x){
	return fp(x, m-2);
}

ll n, k;

int main()
{
	cin >> n >> k;
	
	ll invn = inv(n);
	ll invn1 = inv(n-1);
	/*
	state transfer after one swap action, 1 = first position, other = other n-1 position.
	src pos 	-> dst pos	    -  	action probability to make this transfer
	1 			-> 1            -   stay
	1 			-> other        -   move
	other 		-> other        -   stay
	other 		-> 1            -   move/(n-1)
	*/
	ll move = 2ll * (n-1) % m * invn % m * invn % m;
	ll stay = (1 - move + m) % m;
	ll move1 = move * invn1 % m;
	
	array<ll, 2> dp{};
	// in the begining, the black ball is on 1st position with 100% probability
	dp[0] = 1;
	
	for(ll i=0; i<k; i++){
		array<ll, 2> ndp{}; // new dp
		
		/*
		there are two status transfers to acquire dst pos == 1:
		1 -> 1
			suppose src pos is 1st, i.e. black ball is on 1st position
			action probability to keep dest pos == 1 is stay
		other -> 1
			suppose src pos is xth, x=2..n, i.e. black ball is on any other positions
			action probability to get dest pos == 1 is move1
		*/
		ndp[0] = (1ll * dp[0] * stay % m + 1ll * dp[1] * move1 % m) % m;

		/*
		there are two status transfers to acquire dst pos == any of other positions:
		1 -> other
			suppose src pos is 1st, i.e. black ball is on 1st position
			action probability to keep dest pos == other is move
		other -> other
			suppose src pos is xth, x=2..n, i.e. black ball is on any other positions
			action probability to get dest pos == other is 1 - move1
		*/
		ndp[1] = (1ll * dp[0] * move % m + 1ll * dp[1] * ((1 - move1 + m) % m) % m) % m;
		
		dp = ndp;
	}
	
	/*
	get final probability
	*/
	ll sum = (dp[0] + 1ll * (n + 2ll) % m * (n - 1ll) % m * inv(2) % m * dp[1] % m * invn1 % m) % m;
	
	cout << sum << endl;
	
    return 0;
}


