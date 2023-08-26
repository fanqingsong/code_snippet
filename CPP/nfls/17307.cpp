#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

char *p1, *p2, buf[100000];

#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)

int read() {
    int x = 0, f = 1;
    char ch = nc();
    while (ch < 48 || ch > 57) {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= 48 && ch <= 57) x = x * 10 + ch - 48, ch = nc();
    return x * f;
}

void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}

int n;
const int N = 500005;
bitset<N> bf, bb, bas, c, d;

bool chk(int a) {
    if (a > n / 2) {
        c = bf >> (a - 1);
        c.set(0);
        
        d = bb >> (n - a) & bas >> (a - 1);
        d.set(0);
        
        return (c != d);
    } else {
        c = bf & bas >> (n - a);
        c.set(0);
        
        d = bb >> (n - 2 * a + 1) & bas >> (n - a);
        d.set(0);
        
        return (c != d);
    }
}

int main() {
//    int t = read();
	int t;
	cin >> t;
	
    while (t--) {
        bas.reset();
        bb.reset();
        bf.reset();
        
        cin >> n;
//        n = read();

        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            bas.set(i);
//            v[i] = read();
			cin >> v[i];
        }
        
        int ok = 0;
        for (int i = 1; i <= n; i++) {
            bf.set(v[i]);
            bb.set(n - v[i] + 1);
            
            if (chk(v[i])) {
                putchar('Y');
                putchar('\n');
                ok = 1;
                break;
            }
        }
        
        if (!ok) {
            putchar('N');
            putchar('\n');
        }
    }
}
