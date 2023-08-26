#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n,m;
	cin>>n>>m;
	vector<int>t0(n,0);vector<int>t1(n,0);vector<int>t2(n,0);
	for(int i=0;i<n;i++){
		int tp,x;
		cin>>tp>>x;
		if(tp==0){
			t0.push_back(x);
		}else if(tp==1){
			t1.push_back(x);
		}else{
			t2.push_back(x);
		}
	}
	sort(t0.rbegin(),t0.rend());
	sort(t1.rbegin(),t1.rend());
	sort(t2.rbegin(),t2.rend());
	int nndop,ncnop,cnt=t2[0],cnt1=0,cnt2=1,ans=0,ansn=0;
	vector<int>qzh(n+1,0),vl(n+1,0);
	qzh[1]=t0[0];
	for(int i=2;i<=n;i++){
		qzh[i]=qzh[i-1]+t0[i-1];
	}
	for(int i=2;i<=n;i++){
		if(cnt==0){
			cnt+=t2[cnt2];
			cnt2++;
		}else{
			ansn+=t1[cnt1];
			cnt1++;
			cnt--;
		}
//		ans=max(ans,ansn+t0[m+2-i])
		vl[i]=ansn;
	}for(int i=0;i<=m;i++){
		ans=max(ans,vl[i]+qzh[m-i]);
	}
	cout<<ans<<endl;
}
