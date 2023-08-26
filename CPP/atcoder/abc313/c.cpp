#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

#define int long long

int n;
int a[200005];
bool cmp(int a,int b){
	return a>b;
}
int solve(){
	long long sum = 0;
	
	for(int i=0;i<n;i++){
		sum += a[i];
	}
	
	long long avg = sum / n;
	long long rem = sum % n;
	
	long long diffs = 0;
	
	for(int i=0;i<rem;i++){
		diffs += abs(avg +1- a[i]);
	}
	for(int i=rem;i<n;i++){
		diffs+=abs(avg-a[i]);
	}
	return diffs/2;
}

signed main(){
	cin>>n;

	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	cout<<solve()<<endl;
}
