#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, tmp;
	deque<int> DQ;
	string str;
	cin >> n;

	while (n--) {
		cin >> str;

		if (str == "push_front") {
			cin >> tmp;
			DQ.push_front(tmp);
		}
		else if (str == "push_back") {
			cin >> tmp;
			DQ.push_back(tmp);
		}
		else if (str == "pop_front") {
			if (!DQ.empty()) {
				cout << DQ.front() << "\n";
				DQ.pop_front();
			}
			else cout << -1 << "\n";
		}
		else if (str == "pop_back") {
			if (!DQ.empty()) {
				cout << DQ.back() << "\n";
				DQ.pop_back();
			}
			else cout << -1 << "\n";
		}
		else if (str == "size") {
			cout << DQ.size() << "\n";
		}
		else if (str == "empty") {
			cout << DQ.empty() << "\n";
		}
		else if (str == "front") {
			if (!DQ.empty()) {
				cout << DQ.front() << "\n";
			}
			else cout << -1 << "\n";
		}
		else if (str == "back") {
			if (!DQ.empty()) {
				cout << DQ.back() << "\n";
			}
			else cout << -1 << "\n";
		}
	}

	return 0;

}