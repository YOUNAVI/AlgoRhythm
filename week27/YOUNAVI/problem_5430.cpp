#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Answer Code
void parse(deque<int>& dq) {
	string tmp;
	cin >> tmp;

	int dat = 0;
	for (auto x : tmp) {
		if (x == '[') continue;
		else if (x == ',' || x == ']') {
			dq.push_back(dat);
			dat = 0;
		}
		else {
			dat = 10 * dat + (x - 48);
		}
	}

	if (tmp.length() == 2)
		dq.clear();
}

void print(deque<int>& dq) {
	cout << "[";
	for (int i = 0; i < dq.size(); i++) {
		cout << dq[i];
		if (i != dq.size() - 1)
			cout << ",";
	}
	cout << "]\n";
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, n;
	string str;

	cin >> T;

	while (T--) {
		deque<int> DQ;
		cin >> str;
		cin >> n;

		parse(DQ);

		int r = 0;
		bool isWrong = false;

		for (auto x : str) {
			if (x == 'R') {
				r = 1 - r;
			}
			else if (x == 'D'){
				if (DQ.empty()) {
					isWrong = true;
					break;
				}
				if (r == 0) DQ.pop_front();
				else DQ.pop_back();
			}
		}

		if (r == 1)
			reverse(DQ.begin(), DQ.end());

		if (isWrong) cout << "error\n";
		else print(DQ);
	}

	return 0;

}