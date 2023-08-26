#include <bits/stdc++.h>
using namespace std;
int to[500005][26],fl[500005],cnt=0;
bool vis[500005],isl[500005],fa[500005];
char s[1000006];
int pnt,nxt,ans=0;

void insert(){
	pnt=0;
	for(int i=0;s[i];pnt=nxt,i++){
		nxt=to[pnt][s[i]-'a'];
		fa[nxt]=pnt;
		if(nxt==0){
			cnt++;
			nxt=to[pnt][s[i]-'a']=cnt;
		}
	}
	isl[pnt]=1;
//	cout<<pnt<<"========"<<endl;
}

int solve(){
	pnt=0;

	for(int i=0;s[i];i++){
//		cout << "i=" << i << endl;

		nxt=to[pnt][s[i]-'a'];
		if(isl[pnt]&&vis[pnt]==0){
			vis[pnt]=1;
			ans++;
		}
//		cout<<pnt<<" "<<nxt<<endl;
		if(nxt==0){
			pnt=fl[pnt];
			if(isl[pnt]&&vis[pnt]==0){
				vis[pnt]=1;
				ans++;
			}pnt=to[pnt][s[i]-'a'];
		}else{
			pnt=nxt;
		}
	}

	return ans;
}

void mkfl(){
	queue<int>q;
	root = 0;
	fl[root] = 0;
	
	for(int i=0; i<26; i++){
		if (to[root][i]){
			q.push(to[root][i]);
		}
	}
	
	while(!q.empty()){
		int n=q.front();
		q.pop();

		for(int i=0;i<26;i++){
			if(to[n][i]){
				q.push(to[n][i]);
				fl[to[n][i]]=to[fl[n]][i];
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%s",&s);
		insert();
	}

	pnt=0;
	mkfl();
	fl[0]=0;
	/*
	cout << "-----fail start-------" << endl;
	for(int i=0;i<=cnt;i++){
		cout << fl[i] << endl;
	}
	cout << "-----fail end-------" << endl;
*/
	scanf("%s",&s);
//	cout << "before solve" << endl;
	cout<<solve()<<endl;
}
