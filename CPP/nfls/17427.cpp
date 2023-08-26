#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int n,q,to,az,ok,cnt,ans,mx[3],idx[3],gto[1000006],head[1000006],nxt[1000006],tot,x,y,b,f[1000006],mn[1000006],mne[1000006],nd[1000006],pre[1000006],suf[1000006];
void add(int xx,int yy){
	tot++;
	gto[tot]=yy;
	nxt[tot]=head[xx];
	head[xx]=tot;
}
void dfs1(int a,int fa,int c){
	f[a]=c;
	mn[a]=a;
	mne[a]=1000000000;
	for(int i=head[a];i;i=nxt[i]){
		if(gto[i]!=fa){
			dfs1(gto[i],a,((fa==0)?gto[i]:c));
			mn[a]=min(mn[a],mn[gto[i]]);
			mne[a]=min(mne[a],mn[gto[i]]);
		}
	}
//	cout<<a<<":"<<mn[a]<<"==========---------"<<endl;
}
void dfs2(int a,int fa){
//	if(mp[a].size())cout<<suf[mp[a][mp[a].size()-1]]<<" ";
	for(int i=;i;i--){
		to=mp[a][i];
		if(to!=fa&&mp[a][i+1]!=fa){
			suf[to]=min(suf[mp[a][i+1]],mn[mp[a][i+1]]);
		}else if(i!=mp[a].size()-2&&to!=fa){
			suf[to]=min(suf[mp[a][i+2]],mn[mp[a][i+2]]);
		}
//		cout<<suf[to]<<" ";
	}
//	cout<<endl;
	for(int i=head[a];i&&nxt[i];i=nxt[i]){
		to=nxt[i];
		if(to!=fa&&gto[i]!=fa){
			pre[to]=min(pre[mp[a][i-1]],mn[mp[a][i-1]]);
		}else if(i!=1&&to!=fa){
			pre[to]=min(pre[mp[a][i-2]],mn[mp[a][i-2]]);
		}
	}
	for(int i=0;i<mp[a].size();i++){
//		to=mp[a][i];
		if(mp[a][i]!=fa){
			if(a!=1){
				nd[mp[a][i]]=min(nd[a],suf[mp[a][i]]);
				nd[mp[a][i]]=min(nd[mp[a][i]],pre[mp[a][i]]);
			}
			dfs2(mp[a][i],a);
		}
	}
}
void write(int x) {
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
int main(){
	while(cnt=ans=0,~scanf("%d%d",&n,&q)){
		mp.clear();
		memset(pre,5,sizeof(pre));
		memset(suf,5,sizeof(suf));
		memset(mx,5,sizeof(mx));
		memset(nd,5,sizeof(nd));
		int a;
		for(int i=1;i<n;i++){
			scanf("%d%d",&a,&b);
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		dfs1(1,0,1);
		nd[1]=1e9;
//		cout<<"-------++------\n";
		dfs2(1,0);
		for(int i=0;i<mp[1].size();i++){
			to=mp[1][i];
			ok=0;
			for(int j=0;j<cnt;j++){
				if(mx[j]>mn[to]){
					for(int k=min(2,cnt);k>j;k--){
						mx[k]=mx[k-1];
						idx[k]=idx[k-1];
					}
					mx[j]=mn[to];
					idx[j]=to;
					ok=1;
				}
			}if(cnt<3&&ok==0){
				mx[cnt]=mn[to];
				idx[cnt]=to;
				cnt++;
			}
		}
		while(q--){
			scanf("%d%d",&x,&y);
            x^=ans;
            y^=ans;
			if(y==1){
				swap(x,y);
			}
			if(f[x]==f[y]){
				if(x==1||y==1){
					putchar('2');
					ans=2;
				}else{
					putchar('1');
					ans=1;
				}
				putchar('\n');
			}else{
				
				az=mx[0];
				if(f[x]==idx[0]||f[y]==idx[0]){
					az=mx[1];
					if(f[x]==idx[1]||f[y]==idx[1]){
						az=mx[2];
					}
				}
				if(x==1){
					write(min(mne[y],min(nd[y],az)));
					putchar('\n');
					ans=min(mne[y],min(nd[y],az));
					continue;
				}
				write(min(mne[x],min(mne[y],min(nd[x],min(nd[y],az)))));
				putchar('\n');
				ans=min(mne[x],min(mne[y],min(nd[x],min(nd[y],az))));
			}
		}
	}
}
