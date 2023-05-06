#include <bits/stdc++.h>
using namespace std;
inline __int128 read()
{
    __int128 x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

inline void write(__int128 x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}

int main()
{
	__int128 n;
	
	n = read();
	while(n%2==0){
		n/=2;
	}
	long long ans=1,cnt;
	for(int i=3;n!=1&&i*i<=n;i++){
		cnt=0;
		while(n%i==0){
			n/=i;
			cnt++;
		}
		ans*=(cnt+1);
	}
	if(n!=1){
		ans*=2;
	}
	cout<<ans-1<<endl;
//    __int128 a = read();
//    __int128 b = read();
//    write(a + b);
    return 0;
}

