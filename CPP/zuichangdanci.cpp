#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
	cin >> n;
	
	map<int, vector<string> > mp;

	int line = 0;
	string one, word;
	int maxlen = 0;

	while(true){
		cin >> one;
		word = one;
		if (word[word.size()-1] == '.'){
			word.erase(word.size()-1, 1);
		}
		
		size_t found = word.find("a");
		if (found != string::npos){
			mp[word.size()].push_back(word);
			maxlen = max(maxlen, (int)word.size());
		}
		
		if (one[one.size()-1] == '.'){
			if(mp.size() == 0){
				cout << "NO" << endl;
			} else {
				cout << mp[maxlen][0] << endl;
			}

			mp.clear();

			line++;
			if (line == n){
				break;
			}
		}
	}

    return 0;
}



