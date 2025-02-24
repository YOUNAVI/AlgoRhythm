#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	string tmp, t;
	stack<string> str;
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {

		getline(cin, tmp);
		stringstream ss(tmp);

		while (ss >> t)
			str.push(t);

		cout << "Case #" << i + 1 << ": ";
		while (!str.empty()) {
			cout << str.top() << " ";
			str.pop();
		}
		cout << "\n";
	}

	return 0;

}