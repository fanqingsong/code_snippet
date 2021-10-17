#include <iostream>

using namespace std;

int main() {
	char name[100] = {0};
	int name_len = 0;

	char char_set[100] = {0};
	int char_num = 0;

	cin >> name;

	name_len = strlen(name);
	for (int i = 0; i < name_len; i++) {
		char current_char = name[i];
		bool found = false;

		for (int j = 0; j < char_num; j++) {
			if (char_set[j] == current_char) {
				found = true;
				break;
			}
		}

		if (found == false) {
			char_set[char_num] = current_char;
			char_num ++;
		}
	}

//	cout << char_num << endl;

	int remainder = char_num % 2;
	if (remainder == 0) {
		cout << "CHAT WITH HER!" << endl;
	} else {
		cout << "IGNORE HIM!" << endl;
	}
}
