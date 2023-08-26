
#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 rnd(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
	int len=rnd()%100000+1;
	for(int i=1;i<=len;i++){
		putchar('0'+rnd()%2);
	}
	putchar('\n');
    return 0;
}
