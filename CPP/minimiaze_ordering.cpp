#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/abc242/tasks/abc242_b
*/

int main() {
	string s;

	cin >> s;

//	cout << s << endl;

	string least = s;

	sort(s.begin(), s.end()); // sorting the string
	do {
		cout << s << "\n"; // printing the permutations
	} while (next_permutation(s.begin(), s.end())); // till next_permutations returns false
	return 0;

}




