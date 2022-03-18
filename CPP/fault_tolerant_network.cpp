#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int asd = 0; asd < n; asd++) {
		int t;
		cin >> t;
		int a[100001];
		for (int i = 0; i < t; i++) {
			cin >> a[i];
		}
		int b[100001];
		for (int i = 0; i < t; i++) {
			cin >> b[i];
		}
		long long cnt[30];

		long long cost_ahead_bhead = abs(a[0] - b[0]);
		long long cost_atail_btail = abs(a[t - 1] - b[t - 1]);

		long long ans[8];

		ans[1] = cost_atail_btail + cost_ahead_bhead;

		long long cost_atail_bhead = abs(a[t - 1] - b[0]);
		long long cost_ahead_btail = abs(a[0] - b[t - 1]);

		ans[2] = cost_ahead_btail + cost_atail_bhead;

		cnt[4] = abs(a[1] - b[t - 1]);
		cnt[5] = abs(a[1] - b[0]);
		for (int i = 2; i < t - 1; i++) {
			long long j = abs(a[i] - b[t - 1]);
			cnt[4] = min(j, cnt[4]);
			j = abs(a[i] - b[0]);
			cnt[5] = min(j, cnt[5]);
		}

		cnt[6] = abs(b[1] - a[t - 1]);
		cnt[7] = abs(b[1] - a[0]);

//		cout << "------------------------ ans[]" << endl;
		for (int i = 2; i < t - 1; i++) {
			long long j = abs(b[i] - a[t - 1]);
			cnt[6] = min(j, cnt[6]);
			j = abs(b[i] - a[0]);
			cnt[7] = min(j, cnt[7]);
		}

		ans[3] = cnt[0] + cnt[4] + cnt[6];
		ans[4] = cnt[2] + cnt[5] + cnt[7];
		ans[5] = cnt[1] + cnt[4] + cnt[7];
		ans[6] = cnt[5] + cnt[4] + cnt[6] + cnt[7];
		ans[7] = cnt[3] + cnt[5] + cnt[6];

//		cout << "------------------------ ans[]" << endl;
		long long ansl = ans[1];
		for (int i = 2; i < 8; i++) {
			ansl = min(ansl, ans[i]);
//			cout << ansl << endl;
		}
		cout << ansl << endl;
	}
}