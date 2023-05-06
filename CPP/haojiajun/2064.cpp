#include<stdio.h>
int f1(int x)
{
    int r=1,ans=0;
    while(x>0)
    {
        x/=10;
        ans++;
    }
    for(int i=1;i<=ans;i++)
    r*=10;
    return r;
}
int main()
{
    for(int i=1;i<=100000;i++)
    {
        int k=f1(i);
        if(i*10/k>1) i=k*10;
        int n1=i*10+6,n2=k*6+i;
        if(n1*4==n2) printf("%d %d\n",n1,n2);
    }
    return 0;
 }
