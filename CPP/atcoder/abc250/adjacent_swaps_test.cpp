#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q, t, tt;
	cin >> n >> q;
	int a, s[n + 1], p[n + 1];
	for (int i = 0; i <= n; ++i) {
		s[i] = i;
		p[i] = i;
	}
	for (int i = 0; i < q; ++i) {				//1 2 3 4 5
		cin >> a;								//1
		t = s[p[a]];							//1
		if (p[a] == n) {
			tt = s[p[a] - 1];
			swap(s[p[a]], s[p[a] - 1]);
			swap(p[t], p[tt]);
			//swap(p[a],p[s[p[a-1]]]);
		} else {
			tt = s[p[a] + 1];					//2
			swap(s[p[a]], s[p[a] + 1]);
			swap(p[t], p[tt]);
			//swap(p[a],p[s[p[a+1]]]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << s[i] << ' ';
	}
	return 0;
}