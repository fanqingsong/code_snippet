#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b;
	cin>>a>>b;
	if(b>=a){
		cout<<a;
		cout<<".0000000\n";
		return 0;
	}
	double c=(double)b/a;
	double g=1.00;
	double ret;
	do {
		ret = ((1/sqrt(g))-(1/sqrt(g+1.00)));
		cout << ret << " c=" << c << endl;
		g+=1.0;
	} while(ret > c);

	g-=1.00;
	long long gg=(long long)g;
	long long ans=(gg-1)*b;
	double k=(double)a/sqrt(g);
	int an=(int)k;
	long long answ=an+ans;
	k=(double)(answ%10)+k-an;
	cout<<answ/10<<fixed<<setprecision(7)<<k<<endl;
	return 0;


}
