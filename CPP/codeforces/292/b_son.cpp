#include<bits/stdc++.h>
using namespace std;
struct dsu{
	int fa[504];
	int cnt;
};
dsu rnow,lnow,f[20001],r[20001];int s[20001],e[20001];
int find1(int a,int i){
	return (f[i].fa[a]==a)?(a):(f[i].fa[a]=find1(f[i].fa[a],i));
}
int find2(int a,int i){
	return (r[i].fa[a]==a)?(a):(r[i].fa[a]=find2(r[i].fa[a],i));
}
void merge1(int a,int b,int i){
	a = find1(a, i);
	b = find1(b, i);
	
	if (a == b){
		return;
	}
	
	f[i].cnt++;
	f[i].fa[find1(a,i)]=find1(b,i);
}
void merge2(int a,int b,int i){
	a = find2(a, i);
	b = find2(b, i);

	if (a == b){
		return;
	}

	r[i].cnt++;
	r[i].fa[find2(a,i)]=find2(b,i);
}
int find3(int a){
	return lnow.fa[a]==a?a:(lnow.fa[a]=find3(lnow.fa[a]));
}
int find4(int a){
	return rnow.fa[a]==a?a:(rnow.fa[a]=find4(rnow.fa[a]));
}

void merge3(int a,int b){
	a = find3(a);
	b = find3(b);

	if (a == b){
		return;
	}

	lnow.cnt++;
	lnow.fa[find3(a)]=find3(b);
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		f[0].fa[i]=i;
		r[m+1].fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>s[i]>>e[i];
		f[i]=f[i-1];
		merge1(s[i],e[i],i);
	}
	for(int i=m;i>0;i--){
		r[i]=r[i+1];
		merge2(s[i],e[i],i);
	}
	
	int q;
	cin>>q;
	while(q--){
		int l,e;
		cin>>l>>e;
		lnow=f[l-1];
		rnow=r[e+1];
		for(int i=1;i<=n;i++){
			merge3(lnow.fa[i],find4(rnow.fa[i]));
		}
//		map<int,bool>mp;
//		for(int i=1;i<=n;i++){
//			mp[find3(i)]=1;
////			cout<<find3(i)<<endl;
//		}
//		cout<<mp.size()<<endl;

		cout << n - lnow.cnt << endl;
	}
}
