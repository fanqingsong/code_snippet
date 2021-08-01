#include <iostream>
#include <cmath>

using namespace std;

double getEdgeLen(int cutnum) {
	int halfCutnum = cutnum / 2;
	double edgeLen = 0;
	double halfEdgeLen = 0;

	if (cutnum == 6) {
		return 1;
	}

	halfEdgeLen = getEdgeLen(halfCutnum);
	edgeLen = sqrt(2 - sqrt(4 - pow(halfEdgeLen, 2)));

	return edgeLen;
}

bool checkCutnum(int cutnum) {
	if (cutnum < 6) {
		cout << "cutnum is a positive integer greater than and equal to 6, please correct." << endl;
		return false;
	}

	if (cutnum % 6 != 0) {
		cout << "cutnum must be times 6, please correct." << endl;
		return false;
	}

	while (true) {
		if (cutnum % 2 == 0) {
			cutnum /= 2;
			continue;
		}

		if (cutnum != 3) {
			cout << "cutnum must be 2 power times 6." << endl;
			return false;
		}
	}

	return true;
}

int main() {
	int cutnum = 0;
	double edgeLen = 0;
	double quasiPerimeter = 0;
	double quasiPI = 0;

	//printf("hello world\r\n");

	cout << "please input cutnum for cutting circle, like 6, 12, 24, 48, ..." << endl;

	cin >> cutnum;

	cout << "cutnum is " << cutnum << endl;

	if (!checkCutnum(cutnum)) {
		return 0;
	}

	edgeLen = getEdgeLen(cutnum);

	quasiPerimeter = cutnum * edgeLen;

	quasiPI = quasiPerimeter / 2;

	cout << "the quasi PI is " << quasiPI << endl;

	return 0;
}