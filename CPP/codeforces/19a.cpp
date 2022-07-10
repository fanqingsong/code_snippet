#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <stack>

/*
https://codeforces.com/problemset/problem/19/A
*/

int main() {
	int n;
	map<char, int> counter;

	cin >> n;
	for(int i=0; i<n; i++){
		string team;
		cin >> team;
		
		counter[team[0]] = 0;
	}

	cin.ignore();

	int roundn = n*(n-1)/2;
	for(int i=0; i<roundn; i++){
		cout << "i = " << i << endl;
		string result;
		getline(cin, result);
		
		int dashi = result.find("-");
		char first_tm = result[dashi-1];
		char second_tm = result[dashi+1];
		
		int coloni = result.find(":");
		char first_goal = result[coloni-1];
		char second_goal = result[coloni+1];
		int first_goali = first_goal - '0';
		int second_goali = second_goal - '0';
		
		if(first_goali > second_goali){
			counter[first_tm] += 3;
		} else if (first_goali == second_goali){
			counter[first_tm] += 1;
			counter[second_tm] += 1;
		} else {
			counter[second_tm] += 3;
		}
	}

	vector <pair<int, char> > alltm;
	
	map<char, int>::iterator it;
	for(it=counter.begin(); it!=counter.end(); it++){
		char tm = it->first;
		int score = it->second;
		
		cout << "tm=" << tm << endl;
		cout << "score=" << score << endl;

		pair<int, char> onetm = make_pair(score, tm);
		alltm.push_back(onetm);
	}

	sort(alltm.begin(), alltm.end());
	
	int size = alltm.size();
	for(int i=0; i<size; i++){
		pair<int, char> onetm = alltm[i];
		
		char tm = onetm.second;
		int score = onetm.first;

		cout << "tm=" << tm << endl;
		cout << "score=" << score << endl;
	}

//	vector<pair<int, char> >::iterator itv;
//	for(itv=alltm.begin(); itv!=alltm.end(); itv++){
//		char tm = it->first;
//		int score = it->second;
//
//		cout << "tm=" << tm << endl;
//		cout << "score=" << score << endl;
//	}

	return 0;
}
