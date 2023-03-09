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
    for(int i = 0; i < n; i++)//Ϊ�ж�˳���Ƿ�Ψһ�������˳������������Ҫn��ѭ��
    {
    	cout << "i == " << i << endl;
    	
        int tot = 0;//����Ϊ0�Ķ���ĸ���������һ��˵����������һ������Ψһ�����ܲ���ȷ���������л�
        int u;//��¼����Ϊ0�ĵ�
        for(int j = 0; j < n; j++)if(cnt[j] == 0){tot++, u = j;}
        
        cout << "tot == " << tot << endl;
        
        if(tot == 0)return 0;//�л�
        if(tot > 1)flag = -1;//һ����Ψһ�����ǲ��������˳�����Ϊ֮���п������л�
        ans[i] = u;//��¼��������˳��
        cnt[u] = -1;//�Ѿ��źã���ɸ���
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
            Count[v]++;//���
            if(flag)continue;//����Ѿ��жϳ���������л����Ͳ�������
            int t = topo();
            //cout<<t<<endl;
            if(t == 0)//�л�
            {
                printf("Inconsistency found after %d relations.\n",i);
                flag = 1;
            }
            if(t == 1)//����
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
