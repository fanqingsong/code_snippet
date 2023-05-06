#include <bits/stdc++.h>
using namespace std;

int h,w;

int a[31][31];
int b[31][31];

bool same(){
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if (a[i][j] != b[i][j]){
				return false;
			}
		}
	}

	return true;
}

void rotatev(){
	int temp[31];
	
	for(int j=0; j<w; j++){
		temp[j] = a[0][j];
	}
	
	for(int i=0; i<h-1; i++){
		for(int j=0; j<w; j++){
			a[i][j] = a[i+1][j];
		}
	}
	
	for(int j=0; j<w; j++){
		a[h-1][j] = temp[j];
	}
}

void rotateh(){
	int temp[31];

	for(int i=0; i<h; i++){
		temp[i] = a[i][0];
	}

	for(int j=0; j<w-1; j++){
		for(int i=0; i<h; i++){
			a[i][j] = a[i][j+1];
		}
	}

	for(int i=0; i<h; i++){
		a[i][w-1] = temp[i];
	}
}

int main(){
	cin >> h >> w;

	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			char temp;
			cin >> temp;
			if (temp == '#'){
				a[i][j] = 1;
			} else {
				a[i][j] = 0;
			}
		}
	}

	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			char temp;
			cin >> temp;
			if (temp == '#'){
				b[i][j] = 1;
			} else {
				b[i][j] = 0;
			}
		}
	}

	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if (same()){
				cout << "Yes" << endl;
				return 0;
			}
			
			rotateh();
		}
		
		rotatev();
	}
	
	cout << "No" << endl;
	return 0;
}
