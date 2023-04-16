#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define inf int(0x3f3f3f3f)
#define pi acos(-1.0)
#define lson  l,m,rt<<1
#define rson  m+1,r,rt<<1|1
#define ll long long
#define MAXN 100005
using namespace std;


int n,a,b;
int c[MAXN];
int fa[MAXN];

map<int,int> mp;

void Init()
{
    for(int i=1;i<=n+3;i++)
        fa[i]=i;
}

int findfa(int x)
{
    if(fa[x]==x)return x;
    
    fa[x]=fa[fa[x]];

    return findfa(fa[x]);
}

void Unit(int x,int y)
{
    x=findfa(x);
    y=findfa(y);
    
//    cout << "unit x=" << x << " y=" << y << endl;
    
    if(x==y) return;

    fa[y]=x;
}


int main()
{
    scanf("%d%d%d",&n,&a,&b);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
        mp[c[i]]=i;//ÀëÉ¢»¯
    }
//
//	for(auto it: mp){
//		cout << it.first << "£º" << it.second << endl;
//	}

    Init();
    
    for(int i=1;i<=n;i++)
    {
    	int ci = c[i];
//    	cout << "ci = " << ci << endl;
    	
    	// ar == remainder after subtracting ci from a
    	// br == remainder after subtracting ci from b
    	int ar = a - ci;
    	int br = b - ci;
//    	cout << "ar = " << ar << endl;
//    	cout << "br = " << br << endl;

    	int ar_index = mp[ar];
    	int br_index = mp[br];

//    	cout << "ar_index = " << ar_index << endl;
//    	cout << "br_index = " << br_index << endl;

    	/*
    	a-ci --<no>-- ci --<no>-- b-ci
    	
		if ci has no reaminder of a and b
		i.e. ci do not belong to A set or B set
		so no way to divide p1,...,pn into A set and B set
		*/
    	if(ar_index == 0 && br_index == 0){
    		cout << "NO" << endl;
    		return 0;
		}

    	/*
    	a-ci --<yes>-- ci --<no>-- b-ci

		if ci has the reaminder of a, but no for b
		i.e. ci and ar belong to one set, exactly A set.
		*/
    	if (ar_index != 0 && br_index == 0){
    		Unit(i, ar_index); // ci and ar belong to one set
    		Unit(i, n+1); // ci belong to A set
		}

    	/*
    	a-ci --<no>-- ci --<yes>-- b-ci

		if ci has the reaminder of b, but no for a
		i.e. ci and ar belong to one set, exactly B set.
		*/
    	if (ar_index == 0 && br_index != 0){
    		Unit(i, br_index); // ci and ar belong to one set
    		Unit(i, n+2); // ci belong to B set
		}

    	/*
    	a-ci --<yes>-- ci --<yes>-- b-ci

		if ci has the reaminder of b and a
		i.e. ci and ar belong to one set, but don't know which set
		Then which set should ci belong to
		It depends which sets a-ci and b-ci belong to

		From the below two tables, we can see that ci can be pulled into A and B set simultaneously.

		| a-ci 				| ci 	| 
		------------------------------
		| A(no b-(a-ci)) 	| A 	| 
		| ?(yes b-(a-ci)) 	| depend on the set of b-(a-ci)	|

		| b-ci 				| ci 	| 
		------------------------------
		| B(no a-(b-ci)) 	| B 	| 
		| *(yes a-(b-ci)) 	| depend on the set of a-(b-ci)	|
		*/
    	if (ar_index != 0 && br_index != 0){
    		Unit(i, ar_index); // ci and ar belong to one set
    		Unit(i, br_index); // ci and br belong to one set
		}
    }

	/*
	if A set and B set are merged, for example
	n+1 --<yes>-- x --<yes>-- a-x --<yes>-- b-(a-x) --<yes>-- n+2
	*/
	if (findfa(n+1) == findfa(n+2)){
		cout << "NO" << endl;
		return 0;
	}

    cout << "YES" << endl;
    for(int i=1;i<=n;i++)
    {
        if(findfa(mp[c[i]])==findfa(n+1))
            cout << 0 << endl;
        else if(findfa(mp[c[i]])==findfa(n+2))
            cout << 1 << endl;
		else
            cout << 0 << endl;
    }

    return 0;
}

