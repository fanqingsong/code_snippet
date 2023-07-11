#include <bits/stdc++.h>
using namespace std;
bool operator>(pair<int,int> &a,pair<int,int>&b){
	return a.first>b.first;
}bool operator<(pair<int,int> &a,pair<int,int>&b){
	return a.first<b.first;
}
int main(){
	int n,h;
	cin>>n>>h;
	vector<int>f(n),t(n-1),d(n);
	for(int i=0;i<n;i++){
		cin>>f[i];
	}for(int i=0;i<n;i++){
		cin>>d[i];
	}for(int i=0;i<n-1;i++){
		cin>>t[i];
	}
	h*=12;
	int res=0;
	int tmp=h;
	for(int i=0;i<n;i++){
		h=tmp;
		for(int j=0;j<i;j++){
			h-=t[j];
		}
		if(h<=0){
			break;
		}priority_queue<pair<int,int> >pq;
		for(int j=0;j<=i;j++){
			pq.push(make_pair(f[j],j));
		}
		int ans=0;
		while(h>0){
			h--;
			pair<int,int> num=pq.top();
			pq.pop();
			if(num.first<=0){
				break;
			}
			ans+=num.first;
			pq.push(make_pair(num.first-d[num.second],num.second));
		}
		res=max(res,ans);
	}
	cout<<res<<endl;
}
