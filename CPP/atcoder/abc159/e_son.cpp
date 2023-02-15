#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int dp[15][1005];

int main(){
	int h,w,ll;
	cin>>h>>w>>ll;
	vector<string>v(h+1);
	for(int i=1;i<=h;i++){
		string s;
		cin>>s;
		v[i]+=' ';
		v[i]+=s;
//		cout<<v[i]<<endl;
	}

	dp[1][1]=v[1][1]-'0';
	rep(i,2,h+1){
		dp[i][0]=0;
		dp[i][1]=dp[i-1][1]+v[i][1]-'0';
	}
	rep(i,2,w+1){
		dp[0][i]=0;
		dp[1][i]=dp[1][i-1]+v[1][i]-'0';
	}
	rep(i,2,h+1)rep(j,2,w+1){
		dp[i][j]=dp[i-1][j]+dp[i][j-1]+v[i][j]-'0'-dp[i-1][j-1];
	}/*
	for(int i=0;i<=h;i++){
		for(int j=0;j<=w;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int ans=INT_MAX;
	int n=pow(2,h-1);
	for(int i=0;i<n;i++){
		vector<int>l;
		int num=i,res=0;
		l.push_back(0);
		for(int j=1;num>0;j++){
			if(num%2==1){
				res++;
				l.push_back(j);
			}
			num/=2;
		}
		l.push_back(h);
		int lct=0;
		for(int j=1;j<=w;j++){
			rep(k,1,l.size()){
				if(dp[l[k]][j]-dp[l[k]][lct]-dp[l[k-1]][j]+dp[l[k-1]][lct]>ll){
					if(lct==j-1){
						goto here;
					}
//					if(i==2){
//						cout<<j<<" "<<l[k]<<" "<<lct<<" "<<l[k-1];
//					}
					lct=j-1;
					res++;

				}
			}
		}
		ans=min(ans,res);
		here:;
	}
	cout<<ans<<endl;
}
