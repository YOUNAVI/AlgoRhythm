#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, tmp, ans = 0;
	stack<int> S;
	cin >> N;

	while (N--) {
		cin >> tmp;
		S.push(tmp);
	}

	tmp = S.top();

	while (!S.empty()) {
		if (S.top() > tmp) {
			tmp = S.top();
			ans += 1;
		}
		S.pop();

	}

	cout << ans + 1;
	return 0;

}