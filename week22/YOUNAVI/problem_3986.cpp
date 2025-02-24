#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, ans = 0;
	string tmp;
	stack<char> test;

	cin >> N;

	while (N--) {
		cin >> tmp;

		for (int i = 0; i < tmp.length(); i++) {
			if (test.empty())
				test.push(tmp[i]);
			else if (test.top() == tmp[i])
				test.pop();
			else
				test.push(tmp[i]);
		}

		if (test.empty())
			ans += 1;

		while (!test.empty())
			test.pop();

	}

	cout << ans;

	return 0;

}