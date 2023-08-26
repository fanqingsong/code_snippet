#include <bits/stdc++.h>
using namespace std;
int a[505][1005];
int n;
#define pnt pair<int,int>
#define x first
#define y second
int cnt[505][1005];pair<int,int>mp[505][1005][11];
pair<int,int>pr[505][1005];
int vis[505][1005];
bool dif(pnt a, pnt b) { return a.x != b.x || a.y != b.y; }
int bfs() {
    queue<pnt> q;
    int mx = 0, lth = 0;
    q.push({ 1, 1 });
    vis[1][1] = 1;
    pnt i;
    while (!q.empty()) {
        pnt fnt = q.front();
        q.pop();
        for (int j=0;j<cnt[fnt.x][fnt.y];j++) {
        	i=mp[fnt.x][fnt.y][j];
            if (!vis[i.x][i.y]){
                vis[i.x][i.y] = vis[fnt.x][fnt.y] + 1;
                if (i.x * 3 * n + i.y > mx) {
                    mx = i.x * 3 * n + i.y;
                    lth = vis[i.x][i.y];
                }
                if (i.x == n && i.y == 2 * n - 1 + n % 2) {
                    return vis[i.x][i.y];
                }
                q.push(i);
            }
        }
    }
    return lth;
}
int main() {
    //	cout<<dif({1,0},{1,0})<<endl;
    memset(cnt,0,sizeof(cnt));
    cin >> n;
    pnt tmp1, tmp2;
    for (int i = 1; i <= n; i++) {
        //		cout<<2*n-1+i%2<<"=="<<endl;
        for (int j = 2 - i % 2; j <= 2 * n - 1 + i % 2; j++) {
            cin >> a[i][j];
            tmp1.x = i;
            tmp1.y = j - 1;
            tmp2.x = i;
            tmp2.y = j;


            if (dif(pr[i][j], { i, j - 1 })) {
                //				cout<<"llllllllll"<<endl;
                pr[i][j].x=i;
                pr[i][j].y=j+1;
                pr[i][j+1].y=j;
                pr[i][j+1].x=i;
                if ((a[i][j] == a[i][j - 1])) {
                    mp[i][j][cnt[i][j]]={i,j-1};cnt[i][j]++;
                    mp[i][j][cnt[i][j]]={i,j-2};cnt[i][j]++;
                    mp[i][j-1][cnt[i][j-1]]={i,j};cnt[i][j-1]++;
                    mp[i][j-2][cnt[i][j-2]]={i,j};cnt[i][j-2]++;
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j < 2 * n; j++) {
            if (a[i][j] == a[i - 1][j]) {
                mp[i][j][cnt[i][j]]={i-1,j};cnt[i][j]++;
                mp[i][j][cnt[i][j]]=pr[i-1][j];cnt[i][j]++;
                mp[pr[i][j].x][pr[i][j].y][cnt[pr[i][j].x][pr[i][j].y]]={i-1,j};cnt[pr[i][j].x][pr[i][j].y]++;
                mp[pr[i][j].x][pr[i][j].y][cnt[pr[i][j].x][pr[i][j].y]]=pr[i-1][j];cnt[pr[i][j].x][pr[i][j].y]++;
                mp[i-1][j][cnt[i-1][j]]={i,j};cnt[i-1][j]++;
                mp[i-1][j][cnt[i-1][j]]=pr[i][j];cnt[i-1][j]++;
                mp[pr[i-1][j].x][pr[i-1][j].y][cnt[pr[i-1][j].x][pr[i-1][j].y]]={i,j};cnt[pr[i-1][j].x][pr[i-1][j].y]++;
                mp[pr[i-1][j].x][pr[i-1][j].y][cnt[pr[i-1][j].x][pr[i-1][j].y]]=pr[i][j];cnt[pr[i-1][j].x][pr[i-1][j].y]++;
            }
        }
    }
    cout << bfs() << endl;
}
