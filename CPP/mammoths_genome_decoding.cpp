#include <iostream>
using namespace std;

/*
https://codeforces.com/problemset/problem/747/B
*/

bool try_fill_blank(string genome, int a_count, int c_count, int g_count, int t_count) {
	if (gnome.size() == 0) {
		if (a_count == c_count
		        && c_count == g_count
		        && g_count == t_count) {
			return true;
		}
	}

	char first = genome[0];
	string genome_left = genome.substr(1);

	if (first == '?') {

	}

	switch (first) {
		case 'A':
			a_count++;
			break;
		case 'C':
			c_count++;
			break;
		case 'G':
			g_count++;
			break;
		case 'T':
			t_count++;
			break;
	}
}

int main() {
	int length;
	string genome;

	cin >> length;
	cin >> genome;

	if (genome.length != length) {
		cout << "genome length isn't correct." << endl;
		return;
	}

	int a_count = 0;
	int c_count = 0;
	int g_count = 0;
	int t_count = 0;

	try_fill_blank(genome, a_count, c_count, g_count, t_count);
}