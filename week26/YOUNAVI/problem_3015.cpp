#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int n, tmp;
    stack<pair<int, int>> S;
    long long ans = 0;
    cin >> n;

    while (n--) {

        cin >> tmp;

        int cnt = 1;
        
        while (!S.empty() && S.top().first <= tmp) {
            ans += S.top().second;
            if (S.top().first == tmp) cnt += S.top().second;
            S.pop();
        }
        
        if (!S.empty()) ans++;
        
        S.push({ tmp, cnt });

    }
    cout << ans;

	return 0;

}