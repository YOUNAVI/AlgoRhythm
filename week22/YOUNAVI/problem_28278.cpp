#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, tmp, tmp2;
	stack<int> S;
	cin >> N;
	while (N--) {
		cin >> tmp;
		switch (tmp) {
		case 1: 
			cin >> tmp2;
			S.push(tmp2);
			break;
		case 2:
			if (S.empty()) cout << -1 << "\n";
			else {
				cout << S.top() << "\n";
				S.pop();
			}
			break;
		case 3: 
			cout << S.size() << "\n";
			break;
		case 4: 
			S.empty() ? cout << 1 << "\n" : cout << 0 << "\n";
			break;
		case 5: 
			S.empty() ? cout << -1 << "\n" : cout << S.top() << "\n";
			break;
		}
	}

	return 0;

}