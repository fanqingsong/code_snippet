#include <bits/stdc++.h>
using namespace std;
string s[9]={"###.?????",
"###.?????",
"###.?????",
"....?????",
"?????????",
"?????....",
"?????.###",
"?????.###",
"?????.###"};
char c[105][105];
bool check(int x,int y){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(s[i][j]=='?'||s[i][j]==c[x+i][y+j]){
				continue;
			}else{
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	for(int i=9;i<=n;i++){
		for(int j=9;j<=m;j++){
			if(check(i-8,j-8)){
				cout<<i-8<<" "<<j-8<<endl;
			}
		}
	}
}
