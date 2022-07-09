#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <stack>

int main() {
	string str;
	
	cin >> str;
	
	vector<pair<char, int>> pc;
	stack<pair<char, int>> st;
	
	int size = str.size();
	for(int i=0; i<size; i++){
		pc.push_back(make_pair(str[i], i));
	}

//	cout << "----- before st -------" << endl;

	size = pc.size();
	for(int i=0; i<size; i++){
		pair<char, int> onepc = pc[i];

		char onechar = onepc.first;
		int oneindex = onepc.second;
		
		if(onechar == '('){
			st.push(onepc);
		} else if (onechar == ')'){
			if (st.empty()){
				st.push(onepc);
			} else {
				pair<char, int> topst = st.top();
				char topchar = topst.first;
				int topindex = topst.second;

				if(topchar == '('){
					st.pop();
				} else {
					st.push(onepc);
				}
			}
		}
	}
	
//	cout << "----- before tindex -------" << endl;
	
	set<int> tindex;
	while(!st.empty()){
		pair<char, int> toppc = st.top();
		st.pop();
		
		tindex.insert(toppc.second);
	}
	
//	cout << "----- before print -------" << endl;
	
	size = str.size();
	for(int i=0; i<size; i++){
		if (tindex.count(i) == 0){
			cout << str[i];
		} else {
			if (str[i] == '(') {
				cout << str[i] << ")";
			} else {
				cout << "(" << str[i];
			}
		}
	}
	
	return 0;
}
