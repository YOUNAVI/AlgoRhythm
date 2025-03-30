#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string str;
	queue<int> Q;
	cin >> n;
	
	while (n--) {
		cin >> str;

		if (str == "push") {
			int tmp;
			cin >> tmp;
			Q.push(tmp);
		}
		else if (str == "pop") {
			if (!Q.empty()) {
				cout << Q.front() << "\n";
				Q.pop();
			}
			else cout << -1 << "\n";
		}
		else if (str == "size") {
			cout << Q.size() << "\n";
		}
		else if (str == "empty") {
			cout << Q.empty() << "\n";
		}
		else if (str == "front") {
			if (!Q.empty()) cout << Q.front() << "\n";
			else cout << -1 << "\n";
		}
		else if (str == "back") {
			if (!Q.empty()) cout << Q.back() << "\n";
			else cout << -1 << "\n";
		}
	}

	return 0;

}