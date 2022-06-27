#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>

/*
https://atcoder.jp/contests/abc257/tasks/abc257_c
*/

int N;
string S;

map<int, pair<int, int>> counter;

map<int, pair<int, int>> acc;


int main() {
	cin >> N;
	cin >> S;
	
	for(int i=0; i<N; i++){
		char adult = S[i];
		bool badult = adult =='1' ? true : false;
		
		int weight;
		cin >> weight;
		
//		persons.push_back(make_pair(weight, badult));
		
		if (badult == false){
			counter[weight].first++;
		} else {
			counter[weight].second++;
		}
	}
	
	// print counter
	map<int, pair<int, int>>::iterator it;
	map<int, pair<int, int>>::iterator it_acc_prev;
	for(it=counter.begin(); it!=counter.end(); it++){
		int weight = it->first;
//		cout << "weight = " << weight << endl;
		
		pair<int, int> numbers = it->second;
		
		int first = numbers.first;
		int second = numbers.second;
//		cout << "counter it first = " << first << endl;
//		cout << "counter it second = " << second << endl;
		
		if(it == counter.begin()){
			acc[weight].first = counter[weight].first;
			acc[weight].second = counter[weight].second;
		} else {
			int weight_prev = it_acc_prev->first;
			pair<int, int> numbers_prev = it_acc_prev->second;
			int first_prev = numbers_prev.first;
			int second_prev = numbers_prev.second;
//
//			cout << "first_prev = " << first_prev << endl;
//			cout << "second_prev = " << second_prev << endl;
			
			acc[weight].first = first_prev + first;
			acc[weight].second = second_prev + second;
		}
		
		it_acc_prev = acc.find(weight);
	
//		cout << "acc[weight].first = " << acc[weight].first << endl;
//		cout << "acc[weight].second = " << acc[weight].second << endl;
//		
//		cout << "before loop end" << endl;
	}

//	cout << "before finding" << endl;

	int max_n = max(acc.rbegin()->second.first, acc.rbegin()->second.second);
	
	map<int, pair<int, int>>::iterator it_prev;

	it = acc.begin();
	it++;
	
	it_prev = acc.begin();
	
	for(; it!=acc.end(); ){
		int c_true_n = it_prev->second.first;
		int a_true_n = acc.rbegin()->second.second - it_prev->second.second;
		
		int sum = c_true_n + a_true_n;
		if (max_n < sum){
			max_n = sum;
		}
		
		it++;
		it_prev++;
	}
	
//	cout << "max_n = " << max_n << endl;
	
	cout << max_n << endl;

	return 0;
}
