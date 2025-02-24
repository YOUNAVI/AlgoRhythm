#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, tmp, pos = 1;
	stack<int> S;
	string ret;
	cin >> n;

	while (n--) {
		cin >> tmp;

		while (pos <= tmp) {
			S.push(pos++);
			ret += "+\n";
		}
		if (S.top() != tmp) {
			cout << "NO\n";
			return 0;
		}
		S.pop();
		ret += "-\n";

	}

	cout << ret;

	return 0;

}