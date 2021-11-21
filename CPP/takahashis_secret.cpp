#include <iostream>
using namespace std;

/*
https://atcoder.jp/contests/abc228/tasks/abc228_b
*/


int main() {
	int n, x, a[100000] = {0};
	bool visited[100000] = {false};

	cin >> n >> x;

	for (int i = 1; i <= n; i++) {
		cin >> a[i] ;
	}

	int count = 0;
	int index = x;
	while (true) {
		if (visited[index] == true) {
			break;
		}

		visited[index] = true;
		count ++;

		// visit next
		//cout << "index = " << index << "; next =" << a[index] << endl;
		index = a[index];
	}

	cout << count << endl;
}

