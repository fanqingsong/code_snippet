#include <bits/stdc++.h>
using namespace std;
struct tque{
	int nxt;bool ison;
};tque p[1000006];
int lth=0,fnt=-1,lst=-1,ltm=1;
map<int,int>mp;
int main(){
	int n;
	cin>>n;
	vector<vector<int> >v(n);
	for(int i=0;i<n;i++){
		int l;
		cin>>l;
		while(l--){
			int m;
			cin>>m;
			v[i].push_back(m);
			mp[m]=i;
		}
	}
	mp[-1]=-1;
	while(1){
		string s;
		cin>>s;
		if(s=="STOP"){
			break;
		}else if(s[0]=='E'){
			int x;
			cin>>x;
			p[x].ison=1;
			if(lth==0){
				p[x].nxt=-1;
				fnt=x;lst=x;
			}else{
				bool ok=1;
				for(int i=0;i<v[mp[x]].size();i++){
					if(v[mp[x]][i]==x){
						continue;
					}
					if(p[v[mp[x]][i]].ison&&mp[p[v[mp[x]][i]].nxt]!=mp[x]&&mp[p
					[v[mp[x]][i]].nxt]!=-1){
						p[x].nxt=p[v[mp[x]][i]].nxt;
						p[v[mp[x]][i]].nxt=x;
						ok=0;
					}
				}
				if(ok){
					p[lst].nxt=x;
					p[x].nxt=-1;
					lst=x;
				}
			}
			lth++;
		}else{
			lth--;
			cout<<fnt<<endl;
			p[fnt].ison=0;
			fnt=p[fnt].nxt;
		}
	}
}
