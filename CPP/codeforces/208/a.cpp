#include <bits/stdc++.h>
using namespace std;


map<string, bool> cache;
map<string, bool> hit;


void print_deck(vector<pair<char,char> >& v){
	cout << "------------------- deck:" << endl;

	for(int i=0; i<v.size(); i++){
		cout << v[i].first << v[i].second << " ";
	}
	cout << endl;
}

bool match(pair<char,char> a, pair<char,char> b){
	return a.first==b.first||a.second==b.second;
}

bool dfs(vector<pair<char,char> >& v,
			int n){
	string path;
	for(int i=0; i<n; i++){
		path += v[i].first + v[i].second;
	}

	if (hit[path]){
		return cache[path];
	}

	if (n == 1){
		hit[path] = true;
		cache[path] = true;
		return true;
 	}

	pair<char, char> top = v[n-1];

	if(n>=2){
		pair<char, char> prev = v[n-2];
		
		if (match(top,prev)){
			v[n-2] = top;
			
			if (dfs(v, n-1)){
				cache[path] = true;
				hit[path] = true;
				
				v[n-2] = prev;
				
				return cache[path];
			}
			
			v[n-2] = prev;
		}
	}
	
	if(n >= 4){
		pair<char, char> prev = v[n-4];
		
		if (match(top,prev)){
			v[n-4] = top;
			
			if (dfs(v, n-1)){
				cache[path] = true;
				hit[path] = true;
				
				v[n-4] = prev;

				return cache[path];
			}
			
			v[n-4] = prev;
		}
	}
	
	cache[path] = false;
	hit[path] = true;

	return cache[path];
}

int main(){
	int n;
	cin>>n;

	vector<pair<char,char> >v(n);

	for(int i=0;i<n;i++){
		cin>>v[i].second>>v[i].first;
	}
	
	cout<<(dfs(v,n)?"YES":"NO")<<endl;
}
