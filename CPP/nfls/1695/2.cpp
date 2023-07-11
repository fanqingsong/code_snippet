#include <bits/stdc++.h>
using namespace std;

int ps[27][50005];

int main(){
	string s;
	cin>>s;

	for(int i=0; i<s.size(); i++){
		char one = s[i];
		int char_pos = i+1;
		
		for(int j=1; j<=26; j++){
			int char_val = one - 'a' + 1;
			
			if (char_val == j){
				ps[char_val][char_pos] = ps[char_val][char_pos-1] + 1;
			} else {
				ps[char_val][char_pos] = ps[char_val][char_pos-1];
			}
		}
	}

	int n;
	cin >> n;
	
	while(n--){
		int a, b, c, d;
		
		cin >> a >> b >> c >> d;
		
		int first[27]={0}, second[27]={0};
		
		bool notequal = false;
		
		for(int i=1; i<=26; i++){
			first[i] = ps[i][b] - ps[i][a];
			second[i] = ps[i][d] - ps[i][c];
			
			if (first[i] != second[i]){
				notequal = true;
				break;
			}
		}
		
		if (notequal == true){
			cout << "NE" << endl;
		} else {
			cout << "DA" << endl;
		}
	}
}
