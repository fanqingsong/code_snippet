#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <algorithm>
#include <time.h>

#define SIGMA_SIZE 26
#define lson rt<<1
#define rson rt<<1|1
#define lowbit(x) (x&-x)
#define foe(i, a, b) for(int i=a; i<=b; i++)
#define fo(i, a, b) for(int i = a; i < b; i++);
#pragma warning ( disable : 4996 )

using namespace std;
typedef long long LL;
inline LL LMax(LL a, LL b) { return a>b ? a : b; }
inline LL LMin(LL a, LL b) { return a>b ? b : a; }
inline LL lgcd(LL a, LL b) { return b == 0 ? a : lgcd(b, a%b); }
inline LL llcm(LL a, LL b) { return a / lgcd(a, b)*b; }  //a*b = gcd*lcm
inline int Max(int a, int b) { return a>b ? a : b; }
inline int Min(int a, int b) { return a>b ? b : a; }
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
inline int lcm(int a, int b) { return a / gcd(a, b)*b; }  //a*b = gcd*lcm
const LL INF = 0x3f3f3f3f3f3f3f3f;
const LL mod = 1000000007;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const int maxk = 1e6 + 5;
const int maxn = 4005;


int N, Q, ans;
bool g[maxn][maxn];

void init()
{
    cin >> N >> Q;
    memset(g, false, sizeof(g));
}

void y_update(int xrt, int yrt, int lhs, int rhs, int L, int R)
{
    if (lhs <= L && rhs >= R)
    {
        g[xrt][yrt] ^= 1;
        return;
    }

    int mid = (L + R) >> 1;
    if (lhs <= mid) y_update(xrt, yrt << 1, lhs, rhs, L, mid);
    if (rhs >  mid) y_update(xrt, yrt << 1 | 1, lhs, rhs, mid + 1, R);
}

void x_update(int xrt, int L, int R, int x1, int y1, int x2, int y2)
{
    if (x1 <= L && x2 >= R)
    {
        y_update(xrt, 1, y1, y2, 1, N);
        return;
    }

    int mid = (L + R) >> 1;
    if (x1 <= mid) x_update(xrt << 1, L, mid, x1, y1, x2, y2);
    if (x2 >  mid) x_update(xrt << 1 | 1, mid + 1, R, x1, y1, x2, y2);
}

void y_query(int xrt, int yrt, int L, int R, int y1)
{
    ans ^= g[xrt][yrt];
    if (L == R)
        return;

    int mid = (L + R) >> 1;
    if (y1 <= mid) y_query(xrt, yrt << 1, L, mid, y1);
    else y_query(xrt, yrt << 1 | 1, mid + 1, R, y1);
}

//注意查找的操作
void x_query(int xrt, int L, int R, int x1, int y1)
{
    y_query(xrt, 1, 1, N, y1);
    if (L == R)
        return;

    int mid = (L + R) >> 1;
    if (x1 <= mid) x_query(xrt << 1, L, mid, x1, y1);
    else x_query(xrt << 1 | 1, mid + 1, R, x1, y1);
}

int main()
{
    int all; cin >> all;
    while (all--)
    {
        init();

        char str[3];
        int x1, y1, x2, y2;
        foe(i, 1, Q)
        {
            scanf("%s", str);
            if (str[0] == 'C')
            {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x_update(1, 1, N, x1, y1, x2, y2);
            }
            else
            {
                scanf("%d %d", &x1, &y1);
                ans = 0;
                x_query(1, 1, N, x1, y1);
                printf("%d\n", ans);
            }
        }
        printf("\n");
    }

    return 0;
}
