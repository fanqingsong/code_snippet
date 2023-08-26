#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	bool ans[3]={0,0,0};
	for(int i=0;i<n;i++){
		ans[s[i]-'A']=1;
		if(ans[0]&&ans[1]&&ans[2]){
			cout<<i+1<<endl;
			return 0;
		}
	}
}
