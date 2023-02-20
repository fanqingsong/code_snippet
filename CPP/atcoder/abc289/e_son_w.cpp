#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
int dp[16][1006];
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
			dp[i][j]=dp[i][j-1]+v[i][j]-'0';
//			cout<<dp[j][i]<<" ";
		}
//		cout<<endl;
	}

	int ans=INT_MAX;
	int n=pow(2,h-1);
	for(int i=0;i<n;i++){
		bool x[15]={0};
		int res=0;
		x[0]=1;
		x[h]=1;
		int num=i;
		for(int j=1;num>0;j++){
			if(num%2==1){
				res++;
				x[j]=1;
			}
			num/=2;
		}

//		if(i==2)cout<00<l.size()<<endl;
//		int lct=0;
		int lst=0,pst=0,p=1,ok=0,cnt=0;
		while(lst<w){
			while(p){
				bool flag=1;
                for(int j=0;j<h;j++){
                	cnt+=dp[j][pst+p]=dp[j][lst];
                	if(cnt>ll)
                    {
                        flag=0;
                        break;
                    }
                    if(x[j]){
                    	cnt=0;
					}
				}
				if(flag){
					pst+=p;
					p=min(p*2,w-pst);
				}else{
					p>>=1;
				}
			}

			if(lst==pst){
				ok=1;
				break;
			}

			lst=pst;

			if(lst==w){
				break;
			}

            p=1;
            res++;
            cnt=0;
		}
		
		if(ok){
			continue;
		}
		
		ans=min(ans,res);
	}

	cout<<ans<<endl;
}
