#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#ifndef GET_C_BUFF_SIZE
# define GET_C_BUFF_SIZE (1 << 20)
#endif

char my_getchar(const int fd)
{
    static char buff[GET_C_BUFF_SIZE];
    static char *chr;
    static int  pos = 0;
    static int  ret = 0;

    if (pos >= ret)
    {
        if ((ret = read(fd, buff, GET_C_BUFF_SIZE)) > 0)
        {
            chr = buff;
            pos = 0;
            return (*(chr + pos++));
        }
        else
            return (0);
    }
    else
        return (*(chr + pos++));
}

int read() {
    int x = 0, f = 1;
    char ch = my_getchar(0);
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = my_getchar(0);
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = my_getchar(0);
    }
    return x * f;
}

vector<int> v;
map<int, vector<int> > mp;
int ans, sum[200005];
void dfs(int a, int h) {
    if (h < 0) {
        ans -= sum[a];
        return;
    }
    for (int i = 0; i < mp[a].size(); i++) {
        dfs(mp[a][i], h - 1);
    }
    return;
}
void f(int n) {
    sum[n] = v[n - 1];
    for (int u : mp[n]) {
        f(u);
        sum[n] += sum[u];
    }
}
int main() {
    std::ios::sync_with_stdio(0);

    cin.tie(0);
    cout.tie(0);
    int n = read(), m = read();
    for (int i = 0; i < n; i++) {
        int k = read();
        v.push_back(k);
    }
    for (int i = 2; i <= n; i++) {
        int nm = read();
        //        scanf("%d",&nm);
        mp[nm].push_back(i);
    }
    f(1);
    for (int i = 0; i < m; i++) {
        int x = read(), h = read();
        ans = sum[x];
        dfs(x, h);
        printf("%d\n", ans);
    }
}
