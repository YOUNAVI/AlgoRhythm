#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k;
	long long tmp, ans = 0;
	stack<long long> S;

	cin >> k;

	while (k--) {
		cin >> tmp;
		if (tmp == 0) {
			if (!S.empty()) S.pop();
		}
		else
			S.push(tmp);
	}

	while (!S.empty()) {
		tmp = S.top();
		ans += tmp;
		S.pop();
	}

	cout << ans;

	return 0;

}
