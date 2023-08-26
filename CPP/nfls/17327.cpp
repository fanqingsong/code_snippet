#include <bits/stdc++.h>
using namespace std;
map<int, vector<pair<int, int> > > xmp, ymp;
vector<int> xal, yal;
int cto[6005][6005][4];
int num[6005][6005];
bool vis[6005][6005];
int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
int dfs(int x, int y) {
    vis[x][y] = 1;
    int ans = num[x][y];
    for (int i = 0; i < 4; i++) {
        if (cto[x][y][i] && !vis[x + dx[i]][y + dy[i]]) {
            ans += dfs(x + dx[i], y + dy[i]);
        }
    }
    return ans;
}
int main() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int x, y, x2, y2;
        cin >> x >> y >> x2 >> y2;
        if (y2 < y) {
            swap(y, y2);
        }
        if (x2 < x) {
            swap(x2, x);
        }
        if (x == x2) {
            xal.push_back(x);
            xmp[x].push_back(make_pair(y, y2));
            if (xmp[x].size() != 1 && xmp[x][xmp[x].size() - 2].second == y) {
                xmp[x][xmp[x].size() - 2].second = y2;
                xmp[x].pop_back();
            }
        } else {
            yal.push_back(y);
            ymp[y].push_back(make_pair(x, x2));
            if (ymp[y].size() != 1 && ymp[y][ymp[y].size() - 2].second == x) {
                ymp[y][ymp[y].size() - 2].second = x2;
                ymp[y].pop_back();
            }
        }
    }
    sort(xal.begin(), xal.end());
    int nx=unique(xal.begin(), xal.end())-xal.begin();
    sort(yal.begin(), yal.end());
    int ny=unique(yal.begin(), yal.end())-yal.begin();
    xal.resize(nx);
	yal.resize(ny);
    for (int i = 0; i * 2 < xal.size(); i++) {
        xal.push_back(xal[i]);
    }
    for (int i = 0; i * 2 < yal.size(); i++) {
        yal.push_back(yal[i]);
    }
    sort(xal.begin(), xal.end());
    sort(yal.begin(), yal.end());
    for (int i = 1; i < xal.size(); i++) {
        for (int j = 1; j < yal.size(); j++) {
            for (int k = 0; k < 4; k++) {
                cto[i][j][k] = 1;
            }
            if (i == 1) {
                cto[i][j][0] = 0;  // 0:left
            }
            for (int k = 0; k < ymp[yal[j - 1]].size(); k++) {  // dw
                if (ymp[yal[j - 1]][k].first <= xal[i - 1] && ymp[yal[j - 1]][k].second >= xal[i]) {
                    cto[i][j][1] = 0;
                }
            }
            if (j == 1) {
                cto[i][j][1] = 0;  // 1:down
            }
            for (int k = 0; k < xmp[xal[i - 1]].size(); k++) {  // lf
                if (xmp[xal[i - 1]][k].first <= yal[j - 1] && xmp[xal[i - 1]][k].second >= yal[j]) {
                    cto[i][j][0] = 0;
                }
            }
            if (i == xal.size() - 1) {
                cto[i][j][2] = 0;  // 2:right
            }
            for (int k = 0; k < ymp[yal[j]].size(); k++) {  // up
                if (ymp[yal[j]][k].first <= xal[i - 1] && ymp[yal[j]][k].second >= xal[i]) {
                    cto[i][j][3] = 0;
                }
            }
            if (j == yal.size() - 1) {
                cto[i][j][3] = 0;  // 3:up
            }
            for (int k = 0; k < xmp[xal[i]].size(); k++) {  // rt
                if (xmp[xal[i]][k].first <= yal[j - 1] && xmp[xal[i]][k].second >= yal[j]) {
                    cto[i][j][2] = 0;
                }
            }
        }
    }
    for (int i = 0; i < c; i++) {
        int x, y;
        cin >> x >> y;
        int xn = upper_bound(xal.begin(), xal.end(), x) - xal.begin();
        int yn = upper_bound(yal.begin(), yal.end(), y) - yal.begin();
        num[xn][yn]++;
    }
    int ans = 0;
    for (int j = 1; j < xal.size(); j++) {
        for (int k = 1; k < yal.size(); k++) {
            if (!vis[j][k]) {
                ans = max(dfs(j, k), ans);
            }
        }
    }
    cout << ans << endl;
}
