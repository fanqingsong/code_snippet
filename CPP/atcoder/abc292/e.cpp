
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

#define pb push_back

const int N = 2005;

int g[N][N];

int n, m;

void solve()
{
    vector<vector<int>> in(n + 1), out(n + 1);
    
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        out[x].pb(y);
        in[y].pb(x);
        g[x][y] ++;
    }
    
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        auto din = in[i], dout = out[i];
        for(auto x : din)
            for(auto y : dout)
            {
                if(x == y) continue;
                if(!g[x][y])
                {
                    ++ans;
                    g[x][y] ++;
                    in[y].pb(x);
                    out[x].pb(y);
                }
            }
    }
    
    cout << ans << endl;
}

int main()
{
    cin >> n >> m;

	solve();

    return 0;
}
