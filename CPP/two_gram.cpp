#include <iostream>
#include <iterator>
#include <map>

using namespace std;

/*
https://codeforces.com/problemset/problem/23/A
*/

int main() {
	int n;
	string str;

	cin >> n;
	cin >> str;


	if (n != str.length()) {
		cout << "str length is invalid." << endl;
	}

	map<string, int> counter;

//	counter.insert(pair<string, int>("AA", 1));
//
//	counter["AA"] = 2;
//
//	cout << counter["AA"] << endl;
//
//	cout << counter["AAb"] << endl;


	for (int i = 0; i < n - 1; i++) {
		string two_gram = str.substr(i, 2);

		counter[two_gram] ++;
	}

	map<string, int>::iterator itr;
	string maxStr = "";
	int maxCount = 0;
	for (itr = counter.begin(); itr != counter.end(); ++itr) {
//		cout << '\t' << itr->first
//		     << '\t' << itr->second << '\n';
		if (itr->second > maxCount) {
			maxCount = itr->second;
			maxStr = itr->first;
		}
	}

	cout << maxStr << endl;
}









