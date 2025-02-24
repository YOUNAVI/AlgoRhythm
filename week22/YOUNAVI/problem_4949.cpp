#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string tmp;

	while (true) {
		stack<char> S;
		getline(cin, tmp);
		if (tmp == ".") break;
		
		for (auto i : tmp) {
			switch (i) {
			case '(':
				S.push(i);
				break;

			case '[':
				S.push(i);
				break;

			case ')':
				if (S.empty()) {
					S.push(i);
					break;
				}
				else if (S.top() == '(') {
					S.pop();
					break;
				}
				else {
					S.push(i);
					break;
				}
			case ']':
				if (S.empty()) {
					S.push(i);
					break;
				}
				else if (S.top() == '[') {
					S.pop();
					break;
				}
				else {
					S.push(i);
					break;
				}
			}
		}
		S.empty() ? cout << "yes\n" : cout << "no\n";
	}

	return 0;

}