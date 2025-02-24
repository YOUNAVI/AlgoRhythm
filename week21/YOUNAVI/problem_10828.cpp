#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, t;
	stack<int> S;
	string tmp;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> tmp;

		if (tmp == "push") {
			cin >> t;
			S.push(t);
		}
		else if (tmp == "pop") {
			if (!S.empty()) {
				cout << S.top() << "\n";
				S.pop();
			}
			else cout << -1 << "\n";
		}
		else if (tmp == "size") {
			cout << S.size() << "\n";
		}
		else if (tmp == "empty") {
			S.empty() ? cout << 1 << "\n" : cout << 0 << "\n";
		}
		else if (tmp == "top"){
			if (!S.empty()) cout << S.top() << "\n";
			else cout << -1 << "\n";
		}
	}

	return 0;

}
