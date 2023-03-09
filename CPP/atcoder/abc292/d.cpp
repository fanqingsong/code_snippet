#include <iomanip>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>

#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 200000+10;

int V,E;
int pre[maxn];
int vcnt[maxn];
int lcnt[maxn];

/*初始化*/
void init()
{
	for(int i=1; i<=V; i++)
	{
		pre[i] = i;
		vcnt[i] = 1;
		lcnt[i] = 0;
	}
}

/*查找根节点*/
int find(int x)
{
	int r = x;
	while(r!=pre[r])
	r = pre[r];

	int i = x;//路径压缩
	int j;
	while(i != r)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	
	return r;
}

int main()
{
	scanf("%d%d",&V,&E);

	init();

	int s,t;

	for(int i=0;i<E;i++)
	{
		scanf("%d%d",&s,&t);

		int fx = find(s);
		int fy = find(t);

		if(fx != fy)
		{
			pre[fy] = fx;

			vcnt[fx] += vcnt[fy];
			vcnt[fy] = 0;

			lcnt[fx] += lcnt[fy];
			lcnt[fy] = 0;

			lcnt[fx]++;

		} else {
			lcnt[fx]++;
		}
	}

	for(int i=1; i<=V; i++)
	{
		if(pre[i]==i)
		{
			if (lcnt[i] != vcnt[i]){
				cout << "No" << endl;
				return 0;
			}
		}
	}
	
	cout << "Yes" << endl;
	
	return 0;
}

