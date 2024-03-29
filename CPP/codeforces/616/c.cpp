/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)
#define mp(a,b)       make_pair(a,b)

#define set0(a)       memset(a,0,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define read          freopen("input.txt","r",stdin)
#define write         freopen("output.txt","w",stdout)
#define prflag1(flag) printf("%s\n",(flag)?"YES":"NO")
#define prflag2(flag) printf("%s\n",(flag)?"Yes":"No")
#define prflag3(flag) printf("%s\n",(flag)?"yes":"no")
/* defining macros */

using namespace std;

template <class T> inline T bigmod(T b, T p, T m)
{
    T ret;
    if(p==0) return 1;
    if(p&1)
    {
        ret=(bigmod(b,p/2,m)%m);
        return ((b%m)*ret*ret)%m;
    }
    else
    {
        ret=(bigmod(b,p/2,m)%m);
        return (ret*ret)%m;
    }
}
/* template functions */

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
/* type definition */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction array */

int tc=1;
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=1000;
const long long int mod=1000000007;
/* global declaration */

int adjacents[mx+5][mx+5],mark[mx*mx+5],n,m,ccsize;
char str[mx+5][mx+5];
bool visited[mx+5][mx+5];

void dfs(int x, int y, int cnt)
{
    int i,nx,ny;
    visited[x][y]=true;
    adjacents[x][y]=cnt;
    for(i=0; i<4; i++)
    {
        nx=x+dx4[i];
        ny=y+dy4[i];
        if(nx<n && ny<m && nx>=0 && ny>=0 && !visited[nx][ny] && str[nx][ny]=='.')
        {
            ccsize++;
            dfs(nx,ny,cnt);
        }
    }
}

int main()
{
    int i,j,comp,k,nx,ny,cnt,x;
    cin>>n>>m;
    for(i=0; i<n; i++) scanf("%s",str[i]);
    comp=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(str[i][j]=='.' && !visited[i][j])
            {
                ccsize=1;
                dfs(i,j,comp);
                mark[comp]=ccsize;
                comp++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(str[i][j]=='*')
            {
                cnt=1;
                map<int,bool>mp;
                for(k=0;k<4;k++)
                {
                    nx=i+dx4[k];
                    ny=j+dy4[k];
                    if(str[nx][ny]=='.')
                    {
                        x=adjacents[nx][ny];
                        if(!mp[x]) mp[x]=true,cnt+=mark[x];
                    }
                }
                printf("%d",cnt%10);
            }
            else printf(".");
        }
        nl;
    }
    return 0;
}
