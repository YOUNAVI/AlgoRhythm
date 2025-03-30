#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Answer Code
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {

		int n, tmp;
		long long ans;
		cin >> n;
		stack<pair<int, int>> S;

		if (n == 0) return 0;

		ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> tmp;
            int idx = i;
            while (!S.empty() && S.top().first >= tmp) {
                ans = max(ans, 1LL * (i - S.top().second) * S.top().first);
                idx = S.top().second;
                S.pop();
            }
            S.push({ tmp, idx });
        }
        while (!S.empty()) {
            ans = max(ans, 1LL * (n - S.top().second) * S.top().first);
            S.pop();
        }

		cout << ans << "\n";
	}

	return 0;

}