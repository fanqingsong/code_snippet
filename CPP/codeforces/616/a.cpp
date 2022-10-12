#include <bits/stdc++.h>
using namespace std;
vector <string> v1;
vector<pair<int , int>> vec;

int main()
{
	string s1, s2;
	int cnt1=0, cnt2=0;
	
	cin>>s1>>s2;
	
	int i=0 ;
	
	while(s1[i]=='0')
	{
		cnt1++;
		i++;
	}
	s1.erase(s1.begin() , s1.begin()+cnt1);
	
	int j = 0;
	while(s2[j]=='0')
	{
		cnt2++;
		j++;
	}
	s2.erase(s2.begin() , s2.begin()+cnt2);
	
	if(s1==s2)
		cout<<"="<<endl;
	else if(s1.size() > s2.size())
		cout<<">"<<endl;
	else if (s1.size() <s2.size())
		cout<<"<"<<endl;
	else
	{
	  if(s1<s2)
	    cout<<"<"<<endl;
	  else if(s1>s2)
	    cout<<">"<<endl;
	}
}
