#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>

map<char, string> lookup;

int main() {
	lookup['A'] = ".-";
	lookup['B'] = "-...";
	lookup['C'] = "-.-.";
	lookup['D'] = "-..";
	lookup['E'] = ".";
	lookup['F'] = "..-.";
	lookup['G'] = "--.";
	lookup['H'] = "....";
	lookup['I'] = "..";
	lookup['J'] = ".---";
	lookup['K'] = "-.-";
	lookup['L'] = ".-..";
	lookup['M'] = "--";
	lookup['N'] = "-.";
	lookup['O'] = "---";
	lookup['P'] = ".--.";
	lookup['Q'] = "--.-";
	lookup['R'] = ".-.";
	lookup['S'] = "...";
	lookup['T'] = "-";
	lookup['U'] = "..-";
	lookup['V'] = "...-";
	lookup['W'] = ".--";
	lookup['X'] = "-..-";
	lookup['Y'] = "-.--";
	lookup['Z'] = "--..";


	int n;
	vector<string> codecs(n);
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> codecs[i];
	}

	int size = codecs.size();
	for(int i=0; i<size; i++){
		string oneword = codecs[i];
		
		map<char, string>::iterator it;
		for(it=lookup.begin(); it!=lookup.end(); it++){
			char onechar = it->first;
			string onecode = it->second;

			if(onecode == oneword){
				cout << onechar;
			}
		}
	}

	return 0;
}
