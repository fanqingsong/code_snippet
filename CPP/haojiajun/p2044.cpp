#include <bits/stdc++.h>
using namespace std;
#include <string>

bool is_prime(int num){
	if (num <= 1){
		return false;
	}
	
	for(int i=2; i*i <= num; i++){
		if (num % i == 0){
			return false;
		}
	}
	
	return true;
}

bool is_bool_even(int num){
	int cnt = 0;
	while(true){
		int r = num % 2;
		int q = num / 2;
		
		if (r == 1){
			cnt++;
		}

		if (q==0){
			break;
		}
		
		num = q;
	}
	
	if (cnt % 2 == 0){
		return true;
	}

	return false;
}

int main(){
	int cnt = 0;
	bool found = false;
	int mfloor = 0;
	for(int i=100; i>=1; i--){
		if (is_prime(i) && is_bool_even(i)){
//			cout << "--" << i << endl;
			
			cnt++;
			if (found == false){
				found = true;
				mfloor = i;
			}
		}
	}
	
	cout << cnt << " " << mfloor << endl;
}


