#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

int n;

bool isnp[10005] = {false};

vector<int> primes;

void init(int n)
{
    for (int i = 2; i * i <= n; i++)
        if (!isnp[i])
            for (int j = i * i; j <= n; j += i)
                isnp[j] = 1;
}

int zhishu(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return 0;
	}
	
	return 1;
}

int main(){
	cin >> n;
	
	init(n);

//	cout << "-------" << endl;
	for(int i=2; i<=n; i++){
		if (isnp[i] == 0){
//			cout << i << endl;

			primes.push_back(i);
		}
	}

//	cout << "++++++++" << endl;
	vector<int> addkey;
	for(int i=0; i<primes.size(); i++){
		addkey.push_back(primes[i] + (i+1));

//		cout << addkey[i] << endl;
	}

	int sum = 0;
	for(int i=0; i<addkey.size(); i++){
		if(zhishu(addkey[i])){
//			cout << "===========" << endl;
//			cout << addkey[i] << endl;

			sum += addkey[i];
		}
	}

	cout << (sum % (n+1)) << endl;
}




