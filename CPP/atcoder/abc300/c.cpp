#include <bits/stdc++.h>
using namespace std;

int h,w;
int c[105][105];
map<int, map<int, int> > crossn;

int countn(int i, int j){
	int n;
	for(n=1;;n++){
		if (i+n>h-1
			|| i-n<0
			|| j+n>w-1
			|| j-n<0){
				break;
			}
			
		if (c[i+n][j+n] == 0
			|| c[i-n][j+n] == 0
			|| c[i+n][j-n] == 0
			|| c[i-n][j-n] == 0){
				break;
			}
	}
	
	return n-1;
}

int main(){
	cin >> h >> w;
	
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			char temp;
			cin >> temp;
			
			if (temp == '#'){
				c[i][j] = 1;
			} else {
				c[i][j] = 0;
			}
		}
	}

	for(int i=1; i<h-1; i++){
		for(int j=1; j<w-1; j++){
			int cij = c[i][j];
			if (cij == 1){
				int cnt = countn(i, j);
				if (cnt > 0){
					crossn[i][j] = cnt;
				}
			}
		}
	}

	int N = min(h, w);
	int s[N+1] = {0};

	for(auto ai: crossn){
		for(auto aj: ai.second){
			int cnt = aj.second;
			s[cnt]++;
		}
	}

	for(int i=1; i<=N; i++){
		cout << s[i] << " ";
	}

	return 0;
}
