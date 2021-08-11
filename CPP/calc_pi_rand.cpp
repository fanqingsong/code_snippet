#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
	unsigned long long total = 0;
	unsigned long long hits = 0;
	double distance = 0;
	double pi = 0;
	double xpos = 0;
	double ypos = 0;

	srand((unsigned int)time(NULL));

	cout << "please input dot number:" << endl;
	cin >> total;

	for (unsigned long long i = 0; i < total; i++) {
		xpos = rand() / double(RAND_MAX);
		ypos = rand() / double(RAND_MAX);

		distance = sqrt(pow(xpos, 2) + pow(ypos, 2));
		if (distance <= 1) {
			hits++;
		}
	}

	cout << "hits=" << hits << endl;
	cout << "total=" << total << endl;

	pi = (double(hits) / total) * 4;

	cout << "after caculation, pi=" << pi << endl;
	return 0;
}