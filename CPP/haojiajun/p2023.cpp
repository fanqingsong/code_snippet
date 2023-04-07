#include <bits/stdc++.h>
#include <string>
using namespace std;

int n;

int ai[100], bi[100], ci[100], si[100];
int ailen, bilen, cilen, silen;

int add(int ai[100],
		int ailen,
		int bi[100],
		int bilen,
		int ci[100]){
	int c = 0;
	int maxi = max(ailen, bilen);

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
	
	return clen;
}

int main(){
	cin >> n;

	ci[0] = 1;
	cilen = 1;

	for(int i=1; i<=n; i++){
		memset(si, 0, sizeof(si));
		silen = 0;
		
		/* add ci i times to si */
		for(int j=0; j<i; j++){
			memset(ai, 0, sizeof(ai));
			memcpy(ai, ci, sizeof(ci));
			ailen = cilen;

			memset(bi, 0, sizeof(bi));
			memcpy(bi, si, sizeof(bi));
			bilen = silen;

			memset(si, 0, sizeof(si));
			silen = add(ai, ailen, bi, bilen, si);
		}
		
		memset(ci, 0, sizeof(ci));
		memcpy(ci, si, sizeof(ci));
		cilen = silen;
	}

	string ans;
	for(int i=cilen-1; i>=0; i--){
		ans += char(ci[i] + '0');
	}

//	cout << ans << " ";
	
	int dsum = 0;
	for(int i=0; i<cilen; i++){
		dsum += ci[i];
	}

	cout << dsum << " ";

	bool isPrime = true;
	for(int i = 2; i <= dsum / 2; ++i)
	{
		if(dsum % i == 0)
		{
		  isPrime = false;
		  break;
		}
	}
	
	if (isPrime)
		cout << "T";
	else
		cout << "F";
}




