#include <iomanip>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

/*
https://atcoder.jp/contests/abcxxx/tasks/abcxxx_d
*/

typedef long long ll;

int n, m;

const long long maxn=1e3+11;
long long gra[maxn][maxn],is[maxn],dr[maxn],vis[maxn];

int main()
{
	cin >> n >> m;
    for(ll i=1;i<=m;i++){
        memset(is,0,sizeof(is));
        ll s;

		cin>>s;
        
        ll st[maxn];
        for(ll j=0;j<s;j++){
            cin>>st[j];
            is[st[j]]=1;
        }
        
        for(ll j=st[0];j<=st[s-1];j++){
            if(!is[j]){
                for(ll k=0;k<s;k++){
                    if(!gra[j][st[k]]){
                    	gra[j][st[k]]=1;
						dr[st[k]]++;
					}  
                }
            }
        }
    }
	
	int level = 0;

	do{
		vector<int> stops;

		for(int i=1; i<=n; i++){
			if (dr[i] == 0 && !vis[i]){
				stops.push_back(i);
				vis[i] = true;
			}
		}
		
//		cout << "stops.size() =" << stops.size() << endl;

		if (stops.size() == 0){
			break;
		}

		level++;
		
		for(int i=0; i<stops.size(); i++){
            for(ll j=1;j<=n;j++){
                if(gra[stops[i]][j]){
                    gra[stops[i]][j]=0;
					dr[j]--;
                }
            }
		}
	}while(true);
	
	cout << level << endl;

    return 0;
}



