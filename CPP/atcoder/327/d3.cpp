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
  
  inline bool is_connected(int x, int y){
    x = get(x);
    y = get(y);
    if (x == y) {
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

    dsu d(n);

    vector<int> a(m);
    vector<int> b(m);

    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }

	vector<vector<int>> mp(n);

    for (int i = 0; i < m; i++) {
      	int x = a[i];
      	int y = b[i];

		x--;
		y--;

		mp[x].push_back(y);
		mp[y].push_back(x);
	}

    for (int i = 0; i < n; i++) {
		if (mp[i].size() == 0){
			continue;
		}
		
		int first_neighbor = *mp[i].begin();
		
		for(auto next : mp[i]){
			if (d.is_connected(i, next)){
				cout << "No" << endl;
				return 0;
			}
			
			d.unite(first_neighbor, next);
		}
	}

    cout << "Yes" << '\n';
  }

  return 0;
}


