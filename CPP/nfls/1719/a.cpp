#include<bits/stdc++.h>
using namespace std;

#define M 100005
#define LL long long

struct Pnode{
	int x,y;
}s[M],stk[M];

struct Qnode{
	int k,id;
}q[M];

int n,m;
LL ans[M];

/*
k of line(b,c) is greater than k of line(a, b)
*/
bool check(Pnode a,Pnode b,Pnode c){//比较两条直线的斜率
	return 1LL*(c.y-b.y)*(b.x-a.x)>=1LL*(b.y-a.y)*(c.x-b.x);
}

/*
if b is one the top or right of a
b	| b
____|______
a 	| b
*/
bool cmp1(Pnode A,Pnode B){
	if(A.x!=B.x)return A.x<B.x;
	return A.y<B.y;
}


bool cmp2(Qnode A,Qnode B){
	return A.k<B.k;
}

LL f(int id,int k){//计算答案
	return 1LL*stk[id].x*k+stk[id].y;
}

int main(){
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++)
		scanf("%d %d",&s[i].x,&s[i].y);
		
	int top=0;
	sort(s+1,s+n+1,cmp1);
	
	stk[++top]=s[1];
	stk[++top]=s[2];

	for(int i=3;i<=n;i++){//造出凸包
		while(top>1&&check(stk[top-1],stk[top],s[i]))top--;//将不满足条件的点删去
		stk[++top]=s[i];
	}
	
	for(int i=1;i<=m;i++){
		scanf("%d",&q[i].k); q[i].id=i;
	}
	
	sort(q+1,q+m+1,cmp2);
	int L=1;
	
	for(int i=1;i<=m;i++){
		cout << "i = " << i << " q[i]=" << q[i].k << endl;

		while(L<top&&f(L,q[i].k)<=f(L+1,q[i].k))L++;//计算此时直线的最优点
		ans[q[i].id]=f(L,q[i].k);
	}
	
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	
	return 0;
}


