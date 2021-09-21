#include <iostream>

using namespace std;

// https://codeforces.com/contest/230/problem/A


struct DRAGON {
	int strength;
	int bonus;
};

// sort by strength from small to large
bool sort_dragons(struct DRAGON dragons[100], int level) {
	int strength1, strength2;
	struct DRAGON temp;

	if (level < 2) {
		return true;
	}

	for (int i = 0; i < level - 1; i++) {
		cout << "sort i=" << i << "level=" << level << endl;
		if (i < level - 1) {
			break;
		}

		for (int j = 0; j <= level - i - 2; j++ ) {
			cout << "sort j=" << j << endl;

			strength1 = dragons[j].strength;
			strength2 = dragons[j + 1].strength;
			if (strength1 > strength2) {
//				temp = dragons[j];
//				dragons[j] = dragons[j + 1];
//				dragons[j + 1] = temp;
				memcpy(&temp, &dragons[j], sizeof(struct DRAGON));
				memcpy(&dragons[j], &dragons[j + 1], sizeof(struct DRAGON));
				memcpy(&dragons[j], &temp, sizeof(struct DRAGON));
			}
		}
	}

	return true;
}

bool fight_dragons(int strength, struct DRAGON dragons[100], int level) {
	for (int i = 0; i < level; i++) {
		if (strength > dragons[i].strength) {
			strength += dragons[i].bonus;
		} else {
			return false;
		}
	}

	return true;
}

int main() {
	int strength = 0;
	int level = 0;
	struct DRAGON dragons[100];
	bool is_succeeded = false;

	cin >> strength;
	cin >> level;

	for (int i = 0; i < level; i++) {
		cin >> dragons[i].strength;
		cin >> dragons[i].bonus;
	}

	cout << "level = " << level << endl;

	sort_dragons(dragons, level);

	is_succeeded = fight_dragons(strength, dragons, level);
	if (is_succeeded) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

