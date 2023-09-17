

#include <iostream>
#include <string>
using namespace std;

#define maxn 120

string onestring;
int dp[maxn][maxn];

//https://www.cnblogs.com/coderJiebao/p/Algorithmofnotes30.html

int main() {
	cin >> onestring;
    int len=onestring.size(), ans=1;
    int i, j, L;


    for(i=0; i<len; ++i) {
        dp[i][i] = 1;
        if(i < len-1) {
            if(onestring[i] == onestring[i+1]) {
                dp[i][i+1] = 1;
                ans = 2;
            }
        }
    }


    for(L=3; L<=len; ++L) { 
        for(i=0; i+L-1 < len; ++i) {
            j = i+L-1;              
            if(onestring[i]==onestring[j] && dp[i+1][j-1]==1) {
                dp[i][j] = 1;
                ans = L;            
            }
        }
    }
    
    cout << ans << "\n";

    return 0;
}
