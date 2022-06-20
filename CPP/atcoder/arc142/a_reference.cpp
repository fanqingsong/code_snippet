#include <iostream>
#include <algorithm>
using namespace std;

string inttostr(long long n){
	string ans="";
	int t=1;

	while(n){
		ans+=('0'+n%10);
		n/=10ll;
	}

	for(int i=0,e=ans.size()-1;i<=e;i++,e--){
		swap(ans[i],ans[e]);
	}

	return ans;
}

long long strtoint(string s){
    int len=s.size();
    long long t=1;
    long long answer=0;
    for(int i=len-1;i>=0;i--){
        answer+=(s[i]-'0')*t;
        t*=10;
    }
    return answer;
}

int main(){
	cin.tie(0);
	cout.tie(0);

	long long n,k;
	cin>>n>>k;

	string s=inttostr(k);
	reverse(s.begin(),s.end());
	
	long long k1=strtoint(s);
	if(k1<k){
		cout<<0;
		return 0;
	}
	
	if(n<k){
		cout<<0;
		return 0;
	}
	
	if(k1==k){
		int ans=0;
		while(k<=n){
			k*=10;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	
	int ans=0;
	while(k<=n){
		k*=10;
		ans++;
	}

	while(k1<=n){
		k1*=10;
		ans++;
	}

	cout<<ans;
	return 0;
}
