#include <iostream>
using namespace std;

/*
https://codeforces.com/problemset/problem/1473/B
*/

struct TestCase {
	string s;
	string t;
};

int get_LCM(int a, int b) {
	int greater = 0;

	if (a > b) {
		greater = a;
	} else {
		greater = b;
	}

	while (true) {
		if (greater % a == 0 && greater % b == 0) {
			break;
		}

		greater ++;
	}

	return greater;
}

bool have_LCM(string s, string t) {
	int sLen = s.size();
	int tLen = t.size();

	int lcm = get_LCM(sLen, tLen);

	int sTimes = lcm / sLen;
	int tTimes = lcm / tLen;

	string sLCM = "";
	for (int i = 0; i < sTimes; i++) {
		sLCM += s;
	}

	string tLCM = "";
	for (int i = 0; i < tTimes; i++) {
		tLCM += t;
	}

	if (sLCM == tLCM) {
		return true;
	}

	return false;
}

string get_LCM_STR(string s, string t) {
	int sLen = s.size();
	int tLen = t.size();

	int lcm = get_LCM(sLen, tLen);

	int sTimes = lcm / sLen;

	string sLCM = "";
	for (int i = 0; i < sTimes; i++) {
		sLCM += s;
	}

	return sLCM;
}

int main() {
	int q;

	TestCase tc[2000];

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> tc[i].s;
		cin >> tc[i].t;
	}

	for (int i = 0; i < q; i++) {
		if (have_LCM(tc[i].s, tc[i].t)) {
			cout << get_LCM_STR(tc[i].s, tc[i].t) << endl;
		} else {
			cout << "-1" << endl;
		}
	}

	return 0;
}

