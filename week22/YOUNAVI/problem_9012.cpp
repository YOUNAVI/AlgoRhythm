#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	string tmp;
	while (N--) {
		cin >> tmp;
		stack<char> S;
		for (auto i : tmp) {
			if (i == '(')
				S.push(i);
			else if (i == ')')
				if (S.empty())
					S.push(i);
				else if (S.top() == '(')
					S.pop();
				else
					S.push(i);
		}
		S.empty() ? cout << "YES\n" : cout << "NO\n";
	}

	return 0;

}