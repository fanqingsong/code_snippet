#include <iostream>
#include <map>
#include <set>
using namespace std;
map<int, int>mp;
set<int>s;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int ty;
		cin >> ty;
		if (ty == 1) {
			int x;
			cin >> x;
			mp[x]++;
			s.insert(x);
		} else if (ty == 2) {
			int x, c;
			cin >> x >> c;
			c = min(c, mp[x]);
			mp[x] -= c;
			if (mp[x] == 0)
				s.erase(x);
		} else {
			int mn = *s.begin();
			int mx = *s.rbegin();
			cout << mx - mn << endl;
		}
	}
	return 0;
}