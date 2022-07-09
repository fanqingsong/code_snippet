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
	int t;
	vector<vector<string>> test;

	cin >> t;
	
	for(int i=0; i<t; i++){
		int n;
		cin >> n;
		
		vector<string> sentence;
		for(int j=0; j<n; j++){
			string temp;
			cin >> temp;
			
			sentence.push_back(temp);
		}
		
		test.push_back(sentence);
	}

	int size = test.size();
	for(int i=0; i<size; i++){
		int wsize = test[i].size();
		
		bool is_english = false;
		
		for(int j=0; j<wsize; j++){
			string oneword = test[i][j];
//			if(oneword == "de"){
//				is_chinese = true;
//			} else if (test[i][j] == "a"){
//				is_english = true;
//			}

			if(oneword.length() > 6){
				is_english = true;
			}
		}
		
		if(!is_english) {
			cout << "Pinyin" << endl;
		} else {
			cout << "English" << endl;
		}
	}

	return 0;
}
