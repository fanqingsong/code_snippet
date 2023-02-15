#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
int dp[1006][16];
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
	
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++)
		{
			dp[j][i]=dp[j][i-1]+v[i][j]-'0';
//			cout<<dp[j][i]<<" ";
		}
//		cout<<endl;
	}
	
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
		
//		if(i==2)cout<<l.size()<<endl;
		l.push_back(h);
		int lct=0;
		vector<int> cnt(l.size()-1,0);

		for(int j=1;j<=w;j++){
			rep(k,0,l.size()-1){
				cnt[k]+=dp[j][l[k+1]]-dp[j][l[k]];
				if(cnt[k]>ll){
					res++;
					if(i==2){
//						cout<<j<<" <-j  ->k"<<k<<endl;
					}
					for(int a=0;a<cnt.size();a++){
						cnt[a]=0;
					}
					for(int a=0;a<cnt.size();a++){
						cnt[a]+=dp[j][l[a+1]]-dp[j][l[a]];
						if(i==2){
//							cout<<a<<" "<<cnt[a]<<endl;;
						}
						if(cnt[a]>ll){
							goto here;
						}
					}
					break;
				}
			}
		}
		ans=min(ans,res);
		here:;
	}
	cout<<ans<<endl;
}
