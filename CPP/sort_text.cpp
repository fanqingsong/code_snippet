#include <bits/stdc++.h>
using namespace std;
bool compare1(int a,int b){
	return a>b;
}
int main(){
	int a[10]={1,2,3,4,5,6,7,8,9,0},b[10]={1,2,3,4,5,6,7,8,9,0};
	sort(a,a+10);sort(b,b+10,cmp);
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<10;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;

}
