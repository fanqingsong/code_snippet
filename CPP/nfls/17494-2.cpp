#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef struct node{
	int start,
	int end
} NODE;

bool cmp(NODE a, NODE b){
	if(a.end==b.end){
		return a.start>b.start;
	}

	return a.end<b.end;
}

int l,r;
signed main(){
	int n,m,ans=0;
	cin>>n>>m;
	
	vector<NODE>v;
	v.clear();
	
	for(int i=0;i<n;i++){
		cin>>l>>r;
		if(l>r){
			v.push_back({r,l});
		}
	}

	sort(v.begin(),v.end(),cmp);l=r=-1;
	for(int i=0;i<v.size();i++){
		if (v[i].first>r){
            ans+=2*(r-l);
			r=l=v[i].first;
		}
        r=max(r,v[i].second);
	}
	ans+=(r-l)*2;
	cout<<ans+m<<endl;
}
