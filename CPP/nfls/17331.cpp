#include <bits/stdc++.h>
using namespace std;
int to[500005][26],fl[500005],cnt=0;
bool vis[500005],isl[500005];
char s[1000006];
int pnt,nxt,ans=0;

void insert(){
	pnt=0;
	
	for(int i=0;s[i];i++){
		nxt=to[pnt][s[i]-'a'];
		
		if(nxt==0){
			cnt++;
			
			nxt=cnt;
			to[pnt][s[i]-'a']=cnt;
		}
		
		pnt=nxt;
	}
	
	isl[pnt]=1;
	
//	cout<<pnt<<"========"<<endl;
}

int solve(){
	pnt=0;
	
	for(int i=0;s[i];i++){
//		cout << "i=" << i << endl;
		int tmp=pnt;

		pnt=to[pnt][s[i]-'a'];
		
//		cout<<pnt<<endl;
		for(int j=pnt;j;j=fl[j]){
			ans+=isl[j];
//			if(isl[j])cout<<j<<endl;
			isl[j]=0;
		}
	}

	return ans;
}

void mkfl(){
	queue<int>q;
	q.push(0);
	
	while(!q.empty()){
		int n=q.front();
		q.pop();

		for(int i=0;i<26;i++){
			if(to[n][i]){
				if(n==0){
					fl[to[n][i]]=0;
					q.push(to[n][i]);
					continue;
				}
				q.push(to[n][i]);
				
				fl[to[n][i]]=to[fl[n]][i];
			}else{
				to[n][i]=to[fl[n]][i];
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
