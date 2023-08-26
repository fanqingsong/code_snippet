#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
string tmp = "";
int t=1;
int to[200005][26], ans[200005], twwm[200005];
int cnt = 1;
char s[200005];

int fnd(int pnt, int idx) {
    for (; s[idx]; idx++) {
        pnt = to[pnt][s[idx] - 'a'];
        if (pnt == 0) {
            return 0;
        }
    }
    return ans[pnt];
}
bool insrt(int pnt, int idx) {
    for (; s[idx]; idx++) {
        int nxt = to[pnt][s[idx] - 'a'];
        if (nxt == 0) {
            cnt++;
            nxt = cnt;
            to[pnt][s[idx] - 'a'] = cnt;
        }
        pnt = nxt;
        ans[pnt]++;
    }
    return 0;
}
int dfs() {
    int ans = 0, tp;int t2=strlen(s);
//    cout<<t2<<endl;
    s[t2] = (char)('a');
    s[t2+1]='\0';
    bool cn=0;
    for (int i = 0; i < 26; i++) {
    	s[t2]=('a'+i);
//            
        if (fnd(1, 0)) {
            tp = dfs();
//			printf("%s",s);
//			cout<<tp<<endl;
            ans |= (3 - tp);
            cn=1;
        }
    }
    s[t2]='\0';
    if(cn==0){ans=2;}
    return ans;
}
int main() {
    int n, k;
    cin >> n >> k;
    // odd-sec even-fst==must win
    // even fst odd sec==mustlose
    // fst==both can
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        insrt(1, 0);
        t++;
		memset(s,0,sizeof(s));
    }

    int tp = dfs();

    if (tp == 3) {
        cout << "First" << endl;
    } else  if(tp==2||tp==0){
    	cout<<"Second"<<endl;
	}else {
        cout << (((k & 1) == 0) ? "Second":"First"  ) << endl;
    }
}
