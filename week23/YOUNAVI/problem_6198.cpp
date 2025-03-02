#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long int N, tmp, ans = 0;
	stack<long long int> S;
	cin >> N;

	while (N--) {
		cin >> tmp;

		while (!S.empty() && S.top() <= tmp) {
			S.pop();
		}

		ans += S.size();
		S.push(tmp);

	}

	cout << ans;

	return 0;

}