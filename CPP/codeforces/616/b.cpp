#include <bits/stdc++.h>
using namespace std;
vector <long long> v;
vector<pair<int , int>> vec;

bool rows[105];
long long arr[105][105];
long long mn;

int main()
{
	int n,m;
	long long x;
	cin>>n>>m;

	for(int i=0; i<n; i++)
	{
		mn=100000000000;
		for(int j=0 ; j<m ; j++)
		{
			cin>>x;
			
			if(x<mn)
				mn = x;
		}
		
		v.push_back(mn);
	}
	
	cout << *max_element(v.begin() , v.end());
}
