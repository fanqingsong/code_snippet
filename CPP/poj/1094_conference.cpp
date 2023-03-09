#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<sstream>
#include<functional>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
const int INF = 1e9 + 7;
int T, n, m, cases;
vector<int>Map[maxn];
int Count[maxn];
int ans[maxn];
int topo()
{
    int cnt[maxn];
    memcpy(cnt, Count, sizeof(Count));
    int flag = 1;
    for(int i = 0; i < n; i++)//为判断顺序是否唯一，有序的顺序拓扑排序需要n次循环
    {
    	cout << "i == " << i << endl;
    	
        int tot = 0;//度数为0的顶点的个数，超过一个说明拓扑排序一定不是唯一，可能不能确定，可能有环
        int u;//记录度数为0的点
        for(int j = 0; j < n; j++)if(cnt[j] == 0){tot++, u = j;}
        
        cout << "tot == " << tot << endl;
        
        if(tot == 0)return 0;//有环
        if(tot > 1)flag = -1;//一定不唯一，但是不能立马退出，因为之后有可能是有环
        ans[i] = u;//记录拓扑排序顺序
        cnt[u] = -1;//已经排好，设成负数
        for(int j = 0; j < Map[u].size(); j++)
        {
            int v = Map[u][j];
            cnt[v]--;
        }
    }
    return flag;
}
int main()
{
    while(cin >> n >> m)
    {
        if(!n && !m)break;
        string s;
        int flag = 0;
        for(int i = 0; i <= n; i++)Map[i].clear();
        memset(Count, 0, sizeof(Count));
        for(int i = 1; i <= m; i++)
        {
            cin >> s;
            int u = s[0] - 'A';
            int v = s[2] - 'A';
            Map[u].push_back(v);
            Count[v]++;//入度
            if(flag)continue;//如果已经判断出有序或者有环，就不做处理
            int t = topo();
            //cout<<t<<endl;
            if(t == 0)//有环
            {
                printf("Inconsistency found after %d relations.\n",i);
                flag = 1;
            }
            if(t == 1)//有序
            {
                printf("Sorted sequence determined after %d relations: ",i);
                for(int i = 0; i < n; i++)printf("%c", ans[i] + 'A');
                printf(".\n");
                flag = 1;
            }
        }
        if(!flag)printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
