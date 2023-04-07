#include <bits/stdc++.h>
#include <string>
using namespace std;

string a,b;

int ai[100], bi[100], ci[100], sum[100];

int main(){
	cin>>a>>b;

	for(int i=a.size()-1; i>=0; i--){
		ai[a.size()-i-1] = int(a[i] - '0');
	}

	for(int i=b.size()-1; i>=0; i--){
		bi[b.size()-i-1] = int(b[i] - '0');
	}

	int c = 0;
	int maxi = max(a.size(), b.size());
	for(int i=0; i<maxi; i++){
		int csum = ai[i] + bi[i] + c;

//		cout << "i:" << i << endl;
//		cout << "ai[i]:" << ai[i] << endl;
//		cout << "bi[i]:" << bi[i] << endl;
//		cout << "csum:" << csum << endl;

		ci[i] = csum % 10;
		c = csum / 10;
	}
	
	int clen = maxi;
	if (c == 1){
		ci[maxi] = 1;
		clen++;
	}
	
	string ans;
	for(int i=clen-1; i>=0; i--){
		ans += char(ci[i] + '0');
	}
	
	cout << ans << endl;
}
