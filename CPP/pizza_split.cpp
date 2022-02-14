#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> s = { 0, 360 };
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int b;
		cin >> b;
		sum += b;
		s.push_back(sum % 360);
	}
	sort(s.begin(), s.end());
	int ans = 0;
	for (int i = 0; i < int(s.size()) - 1; i++) {
		ans = max(ans, s[i + 1] - s[i]);
	}
	cout << ans << endl;
	return 0;
}