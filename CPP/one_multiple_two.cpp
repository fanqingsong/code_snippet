#include <bits/stdc++.h>
using namespace  std;


/*
https://atcoder.jp/contests/abc232/tasks/abc232_a
*/


int main() {
	string inputs;

	cin >> inputs;

	char first = inputs[0];
	char second = inputs[2];

	int one = first - '0';
	int two = second - '0';

	cout << one *two << endl;

}