/**
 *    author:  tourist
 *    created: 10.07.2022 18:40:44
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;

  while (tt--) {
    int n, m;
    cin >> n >> m;

    dsu d(2 * n);
    
    vector<int> a(m);
    vector<int> b(m);
    
    for (int i = 0; i < m; i++) {
      cin >> a[i];
  	}

    for (int i = 0; i < m; i++) {
      cin >> b[i];
  	}

    for (int i = 0; i < m; i++) {
	  int x = a[i];
	  int y = b[i];
	  
	  x--;
	  y--;
      
      d.unite(x, y + n);
      d.unite(x + n, y);
    }
    
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (d.get(i) == d.get(i + n)) {
        ok = false;
      }
    }
    
    cout << (ok ? "Yes" : "No") << '\n';
  }
  
  return 0;
}
