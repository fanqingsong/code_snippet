#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <set>
using namespace std;


/*
https://codeforces.com/problemset/problem/762/B
*/

#define MAX_M 300000
#define TYPE_USB 0
#define TYPE_PS2 1

int main() {
	int a, b, c;
	int m;
	priority_queue <int, vector<int>, greater<int> > usb_mice;
	priority_queue <int, vector<int>, greater<int> > ps2_mice;

	cin >> a >> b >> c;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int price;
		string type;

		cin >> price;
		cin >> type;

		if (type == "USB") {
			usb_mice.push(price);
		} else if (type == "PS/2") {
			ps2_mice.push(price);
		}
	}

	int usb_host_left = a;
	int ps2_host_left = b;
	int both_host_left = c;

	int count = 0;
	long long cost = 0;
	while (usb_host_left > 0) {
		if (usb_mice.empty()) {
			break;
		}

		count ++;
		int price = usb_mice.top();
		usb_mice.pop();
		cost += price;

		usb_host_left --;
	}

	while (ps2_host_left > 0) {
		if (ps2_mice.empty()) {
			break;
		}

		count ++;
		int price = ps2_mice.top();
		ps2_mice.pop();
		cost += price;

		ps2_host_left --;
	}

	while (both_host_left > 0) {
		if (usb_mice.empty() && ps2_mice.empty()) {
			break;
		}

		count ++;

		if (!usb_mice.empty() && !ps2_mice.empty()) {
			int usb_price = usb_mice.top();
			int ps2_price = ps2_mice.top();

			if (usb_price < ps2_price) {
				usb_mice.pop();
				cost += usb_price;
			} else {
				ps2_mice.pop();
				cost += ps2_price;
			}
		} else if (!usb_mice.empty() && ps2_mice.empty()) {
			int price = usb_mice.top();
			usb_mice.pop();
			cost += price;
		} else if (usb_mice.empty() && !ps2_mice.empty()) {
			int price = ps2_mice.top();
			ps2_mice.pop();
			cost += price;
		}

		both_host_left --;
	}

	cout << count << " " << cost << endl;
}


