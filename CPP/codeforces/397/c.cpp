#include <bits/stdc++.h>
using namespace std;
#define LL long long

const long long MAXC = 20000;
LL n;
map<LL, LL> mp;
LL mod = 1e9+7;
LL jc[MAXC+5], invjc[MAXC+5];


LL ksm(LL b, LL p){
	LL res = 1;
	for(;p;){
		if(p&1){
			res =res* b % mod;
		}

		b *= b%mod;
		p>>=1;
	}
	
	return res;
}

void init(){
	jc[0] = 1;
	for(LL i=1; i<=MAXC; i++){
		jc[i] = i * jc[i-1];
		jc[i] %= mod;
	}
	
	invjc[MAXC] = ksm(jc[MAXC], mod-2);
	for(LL i=MAXC-1; i>=0; i--){
		invjc[i] = ((i+1)*invjc[i+1])%mod;
	}
}

LL C(LL m, LL n){
	cout << "m=" << m << "n=" << n << endl;
	
	LL res = 1;
	
	cout << "jc[m]=" << jc[m] << endl;
	cout << "invjc[n]=" << invjc[n] << endl;
	cout << "invjc[m-n]=" << invjc[m-n] << endl;
	
	res = (((jc[m]*invjc[n])%mod)*invjc[m-n])%mod;
	
	cout << "res=" << res << endl;
	
	return res;
}

int main(){
	init();
	
	cin >> n;
	for(LL i=0; i<n; i++){
		LL temp;
		cin >> temp;
		
		for(int j=2; j*j<=temp; j++){
			while(temp%j==0){
				mp[j]++;
				temp/=j;
			}
		}

		if (temp>1) {
			mp[temp]++;
		}
	}
	
//	for(auto& t : mp){
//		cout << "k=" << t.first << "v=" << t.second << endl;
//	}

	LL res = 1;
	for(auto& t: mp){
		LL item_count = C(t.second+n-1, n-1);
		
		cout << "item count=" << item_count << endl;
		
		res *= item_count;
		res %= mod;
	}
	
	cout << res << endl;
}


