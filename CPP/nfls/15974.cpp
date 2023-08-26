#include <bits/stdc++.h>
using namespace std;
/*
Author yourdad
date -
status WATLERECEMLEOLEUKEJFPE
*/
int cnt=0;
string s;
int mx[500005][2],mn[500005][2];//0isg
int dfs(int idx){
	cnt++;int pnt=cnt;
//	cout<<idx<<" ";
	if(s[idx]=='0'){
		mx[pnt][0]=0;
		mx[pnt][1]=1;
		mn[pnt][0]=0;
		mn[pnt][1]=1;
		return idx;
	}else if(s[idx]=='1'){
		int lst=dfs(idx+1);
		mx[pnt][0]=max(mx[pnt+1][0],mx[pnt+1][1]);
		mn[pnt][0]=min(mn[pnt+1][0],mn[pnt+1][1]);
		mx[pnt][1]=mx[pnt+1][0]+1;
		mn[pnt][1]=mn[pnt+1][0]+1;
		return lst;
	}else{
		int bl=cnt+1,bbl=idx+1,bbr=dfs(bbl)+1,br=cnt+1;int l=dfs(bbr);
		mx[pnt][0]=max(mx[bl][0]+mx[br][1],mx[bl][1]+mx[br][0]);
		mn[pnt][0]=min(mn[bl][0]+mn[br][1],mn[bl][1]+mn[br][0]);
		mx[pnt][1]=mx[bl][0]+mx[br][0]+1;
		mn[pnt][1]=mn[bl][0]+mn[br][0]+1;
		return l;
	}
}
int main(){
	cin>>s;
	dfs(0);
	cout<<max(mx[1][0],mx[1][1])<<" "<<min(mn[1][0],mn[1][1])<<endl;
}

