#include <bits/stdc++.h>
using namespace std;

int main() {
    mt19937 rnd(chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count());
	cout<<rnd()%10000+1<<" "<<rnd()%10000+1;

    return 0;
}
