#include <bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,mv_tm;
};
int mvx[4]={1,-1,1,-1},mvy[4]={1,1,-1,-1};
bool b[1501][1501];
int main(){
	int sa,sb,ea,eb,n;
	cin>>n;
	vector<string>v(n);
	cin>>sa>>sb>>ea>>eb;
	sa--;sb--;ea--;eb--;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	queue<Node>q;
	q.push({sa,sb,0});
	b[sa][sb]=1;
	while(!q.empty()){

		int r=q.front().x;
		int c=q.front().y;
		int times=q.front().mv_tm;
		if(r==ea&&c==eb){
			cout<<times<<endl;
			return 0;
		}
		for(int i=0;i<4;i++){
			r+=mvx[i];
			c+=mvy[i];
			while(r>=0&&c>=0&&r<n&&c<n&&v[r][c]!='#'){
                if(b[r][c]==1) {
					r+=mvx[i];
					c+=mvy[i];
					continue;
				}

				b[r][c]=1;
				q.push({r,c,times+1});

				r+=mvx[i];
				c+=mvy[i];
			}
			r=q.front().x;
			c=q.front().y;
			times=q.front().mv_tm;

		}
		q.pop();
	}
	cout<<-1<<endl;
}
