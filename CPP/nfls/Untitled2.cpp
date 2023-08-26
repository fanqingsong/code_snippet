#include <bits/stdc++.h>
using namespace std;
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long g = exgcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return g;
}
int main() {
    //	y x-a/b*y
    long long a, b, x, y, xx, yy, m, n, l;
    cin >> xx >> yy >> m >> n >> l;
    
    a = n - m, b = x;
    if (m == n) {
        cout << "Impossible\n";
        return 0;
    }
    long long g = exgcd(a, l, x, y);
    if (abs(yy - xx) % g != 0) {
        cout << "Impossible\n";
        return 0;
    }
    l/=abs(g);
    cout << ((((xx-yy)/g*x)%l)+l)%l << endl;
}
