#include <bits/stdc++.h>
using namespace  std;

int lcm(int a, int b) {
	for (int i = a;; i += a) {
		if (i % b == 0) {
			return i;
		}
	}
}

void judge_() {
	string s, s1;
	cin >> s >> s1;

	int a = s.size(), b = s1.size();

	int lcm_num = lcm(a, b);

	int atimes = lcm_num / a;
	int btimes = lcm_num / b;

	string s2, s3;
	for (int i = 0; i < atimes; i++) {
		s2 += s;
	}
//	cout << b << endl;
	for (int i = 0; i < btimes; i++) {
		s3 += s1;
	}

//	cout << " ------------- " << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << " ------------- " << endl;

	for (int i = 0; i < s3.size(); i++) {
		if (s2[i] != s3[i]) {
			cout << "-1" << endl;
			return;
		}
	}
	cout << s2 << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		judge_();
	}
}