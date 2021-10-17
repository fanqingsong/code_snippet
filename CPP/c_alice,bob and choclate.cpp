#include <iostream>
using namespace std;

int main() {
	int n, all = 0;
	int b[100000];
	cin >> n;
	for (int d = 0; d < n; d++) {
		cin >> b[d];
		all += b[d];
	}
	int half = all / 2;
	for (int i = 0;; i++) {
		if (half >= b[i]) {
			half -= b[i];
		} else {
			half = i;
			break;
		}
	}
	int atime=0,btime=0;
	for(int j=half-1;j>=0;j--){
		atime+=b[j];
	}
	for(int h=half+1;h<n;h++){
		btime+=b[h];
	}
	if(btime>=atime){
		atime=half+1;
	}else{
		atime=half;
	}
	cout<<atime<<" "<<n-atime;
	return 0;
}