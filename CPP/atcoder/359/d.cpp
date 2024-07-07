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
const ll mod = 998244353;

ll n, k;
string s;

const ll nsize = 1005;
const ll kstatesize = 1<<10 + 5;
bool mirror[kstatesize];

ll dp[nsize][kstatesize];

/*
	kseq is represented by bitseq of k bit length
	10101011111111
	this function is to check if it is of mirror structure
	mirror structure has central symmetry, for example
	101
	11011
*/
bool checkmirror(ll kseq){
	/*
	iterate from 0 positon to half position k>>1
	1111111111111111111111111111
		l                  r
	*/
	for(int i=0; i<(k>>1); i++){
		ll l = i;
		ll r = k - i -1;
		
		ll lbit = (kseq>>l)&1;
		ll rbit = (kseq>>r)&1;
		
		if (lbit != rbit){
			return false;
		}
	}
	
	return true;
}

int main()
{
	cin >> n >> k;
	cin >> s;

	for(int i=0; i<(1<<k); i++){
		mirror[i] = checkmirror(i);
	}

	/*
	initialize the first k seq of dp
	*/
	for(int i=0; i<(1<<k); i++){
		// only non-mirror seq takes effect
		if (mirror[i]){
			continue;
		}
		
		/*
		suppose the first k seq follow the i case
		increase dp
		*/
		dp[k-1][i]++;

		/*
		then detect if any break with i case,
		if yes, decrease dp
		*/
		for(int j=0; j<k; j++){
			/*
			in i case, for each bit,
			0	--	A
			1   --  B
			*/
			ll jbitpos = k - j - 1;
			ll jbit = (i>>jbitpos)&1;
			
			if (s[j]=='A' && jbit==1){
				dp[k-1][i]--;
				break;
			}
			
			if (s[j]=='B' && jbit==0){
				dp[k-1][i]--;
				break;
			}
		}
//		cout<<dp[k-1][i];
	}
	
	/*
	now iterate from k to n-1 to calculate the following dp
	*/
	for(int i=k; i<n; i++){
		/*
		iterate each non-mirror cases
		*/
		for(int j=0; j<(1<<k); j++){
			// as of this case j, the previous state i-1 is not a good string
			// i.e. dp == 0
			// for the new added char of i index, the new string is still not a good string
			// so skip
			if (dp[i-1][j] == 0){
				continue;
			}
			
			// if the new added char of i index is not A,
			// the possible value is B or ?
			// let's make the possible state transfer
			if (s[i]!='A'){
				// newk is appended by B, and removed the left-most char
				ll newk = ((j<<1)|1)&((1<<k)-1);
//				cout<<newk;
				// if newk is not mirror, the new string is a good string
				// newk is not mirror, make state stranfer
				if (!mirror[newk]){
					dp[i][newk] = (dp[i][newk] + dp[i-1][j]) % mod;
				}
			}

			// if the new added char of i index is not B,
			// the possible value is A or ?
			// let's make the possible state transfer
			if (s[i]!='B'){
				// newk is appended by A, and removed the left-most char
				ll newk = (j<<1)&((1<<k)-1);
//				cout<<newk;
				// if newk is not mirror, the new string is a good string
				// newk is not mirror, make state stranfer
				if (!mirror[newk]){
					dp[i][newk] = (dp[i][newk] + dp[i-1][j]) % mod;
				}
			}
		}
//		for(int j=0;j<(1<<k);j++)cout<<dp[i][j];
//		cout<<'\n';
	}
	
	// now we get dp[n-1],
	// let calculate total number of all states
	ll ans = 0;
	for(int i=0; i<(1<<k); i++){
		ans = (ans + dp[n-1][i]) % mod;
//		cout<<dp[n-1][i];
	}

	cout << ans << endl;

    return 0;
}


