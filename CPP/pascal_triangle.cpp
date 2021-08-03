#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int cutnum = 0;
	double edgeLen = 0;
	double quasiPerimeter = 0;
	double quasiPI = 0;

	//printf("hello world\r\n");

	cout << "please input cutnum for cutting circle, like 6, 12, 24, 48, ..." << endl;

	cin >> cutnum;

	cout << "cutnum is " << cutnum << endl;

	cout << "Now check cutnum" << endl;

	if (!checkCutnum(cutnum)) {
		return 0;
	}

	cout << "Now calculate edge length." << endl;

	edgeLen = getEdgeLen(cutnum);

	quasiPerimeter = cutnum * edgeLen;

	quasiPI = quasiPerimeter / 2;

	cout << "the quasi PI is " << quasiPI << endl;

	return 0;
}