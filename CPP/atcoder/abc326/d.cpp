#include <bits/stdc++.h>
using namespace std;
#define int long long
char c[6][6];
signed main(){
	int n;string r,cl;
	cin>>n>>r>>cl;
	for(int msk=0;msk<1ll<<(n*n);msk++){
		memset(c, 0, sizeof(c));
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int tp=(msk>>((i*n+j)))&1;
				if(tp==0)c[i][j]='.';
				else c[i][j]='O';
//				putchar(c[i][j]);
			}
//			putchar('\n');
		}
//		putchar('\n');
		bool ok=1;
		for(int i=0;i<n;i++){
			char ch='.';
			for(int j=0;j<n;j++){
				if(c[i][j]!='.'){
					ch=',';
					if(c[i][j]=='O'){
						c[i][j]=r[i];
					}
					if(c[i][j]!=r[i]){
						ok=0;
					}
					break;
				}
			}
			if(ch=='.')ok=0;
			ch='.';
			for(int j=0;j<n;j++){
				if(c[j][i]!='.'){
					ch=',';
					if(c[j][i]=='O'){
						c[j][i]=cl[i];
					}
					if(c[j][i]!=cl[i]){
						ok=0;
					}
					break;
				}
			}
			if(ch=='.')ok=0;
		}
		if(ok){
			puts("Yes");
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(c[i][j]=='O')c[i][j]='A';
					putchar(c[i][j]);
				}
				putchar('\n');
			}
			return 0;
		}
	}
	puts("No");
}
/*
things to check
1.initallize(especially multicases)
2.int overflow/long long mle
3.if make the ans is hard , try 2-divided
4.memory &b-&a
5.function canshu position
*/

