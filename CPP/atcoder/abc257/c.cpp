#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>

/*
https://atcoder.jp/contests/abc257/tasks/abc257_c
*/

int N;
string S;

vector<pair<int, bool>> persons;


int main() {
	cin >> N;
	cin >> S;
	
	for(int i=0; i<N; i++){
		char adult = S[i];
		bool badult = adult =='1' ? true : false;
		
		int weight;
		cin >> weight;
		
		persons.push_back(make_pair(weight, badult));
	}

//	int size = persons.size();
//	for(int i =0; i<size; i++){
//		cout << persons[i].first << " ";
//		cout << persons[i].second << " ";
//	}

	sort(persons.begin(), persons.end());

	int size = persons.size();

	for(int i =0; i<size; i++){
		cout << persons[i].first << " " << endl;
		cout << persons[i].second << " " << endl;
	}

	int c_pure_n = 0;
	int a_pure_n = 0;

	int c_end_index = -1;
	int a_end_index = size;
	
	// search from head
	for(int i=0; i<size; i++){
		pair<int, bool> one = persons[i];
		int weight = one.first;
		int badult = one.second;
		
		if (badult == true){
			a_end_index = i;
			break;
		} else {
			c_pure_n ++;
		}
	}

	// search from tail
	for(int i=size-1; i>=0; i--){
		pair<int, bool> one = persons[i];
		int weight = one.first;
		int badult = one.second;

		if (badult == false){
			c_end_index = i;
			break;
		} else {
			a_pure_n ++;
		}
	}

	cout << "c_pure_n = " << c_pure_n << endl;
	cout << "a_pure_n = " << a_pure_n << endl;

	if (c_end_index < a_end_index){
		cout << c_pure_n + a_pure_n << endl;
		return 0;
	}

	// search the overlapping scope [a_end_index, c_end_index]
	int c_acc[N] = {0};
	int a_acc[N] = {0};
	for(int i=a_end_index; i<=c_end_index; i++){
		pair<int, bool> one = persons[i];
		int weight = one.first;
		int badult = one.second;

		if (badult == true){
			if (i == 0){
				a_acc[i] = 1;
				c_acc[i] = 0;
			}else {
				a_acc[i] = a_acc[i-1] + 1;
				c_acc[i] = c_acc[i-1];
			}
		}else {
			if(i == 0){
				a_acc[i] = 0;
				c_acc[i] = 1;
			} else {
				a_acc[i] = a_acc[i-1];
				c_acc[i] = c_acc[i-1] + 1;
			}
		}
	}

	int max_n = max(a_acc[c_end_index], c_acc[c_end_index]);

	for(int i=a_end_index+1; i<=c_end_index; i++){
		int c_true_n = c_acc[i-1];
		int a_true_n = a_acc[c_end_index] - a_acc[i-1];
		
		int sum = c_true_n + a_true_n;
		if (max_n < sum){
			max_n = sum;
		}
	}
	
	cout << "max_n = " << max_n << endl;
	
	cout << c_pure_n + max_n + a_pure_n << endl;

	return 0;
}
