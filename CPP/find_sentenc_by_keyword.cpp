#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int len = 0;
	vector<string> sentence_vec;
	vector<string> keyword_vec;
	string one_sentence;
	string one_keyword;
	string keyword_line;

	cout << "please number of sentences:" << endl;
	cin >> len;

	// consume the new line
	getline(cin, one_sentence);

	cout << "please input sentences:" << endl;
	for (int i = 0; i < len; i++) {
//		cout << "i=" << i << endl;
		getline(cin, one_sentence);
//		cout << one_sentence << endl;
		sentence_vec.push_back(one_sentence);
	}

	cout << "all sentence your inputted:" << endl;
	for (int i = 0; i < len; i++) {
		cout << sentence_vec[i] << endl;
	}

	cout << "please input keywords:" << endl;
	getline(cin, keyword_line);
	// Used to split string around spaces.
	istringstream ss(keyword_line);

	// Traverse through all words
	// while loop till we get
	// strings to store in string word
	while (ss >> one_keyword) {
		keyword_vec.push_back(one_keyword);
	}

	cout << "the keywords you inputed:" << endl;
	for (int i = 0; i < keyword_vec.size(); i++) {
		cout << keyword_vec[i] << endl;
	}

	// search keyword from sentences
	for (int i = 0; i < sentence_vec.size(); i++) {
		one_sentence = sentence_vec[i];

		bool all_matched = true;
		for (int j = 0; j < keyword_vec.size(); j++) {
			one_keyword = keyword_vec[j];

			size_t found = one_sentence.find(one_keyword);
			if ( found == string::npos ) {
				all_matched = false;
				break;
			}
		}

		if (all_matched) {
			cout << "matched: " << one_sentence << endl;
		}
	}

	return 0;
}
