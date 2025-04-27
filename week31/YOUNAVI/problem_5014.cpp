#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int vis[2000001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	int dx[2] = { U, -D };
	queue<int> Q;
	
	vis[S] = 1;
	Q.push(S);

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		if (cur == G) {
			cout << vis[cur] - 1;
			return 0;
		}

		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + dx[dir];
			if (nx <= 0 || nx > F) continue;
			if (vis[nx] > 0) continue;
			vis[nx] = vis[cur] + 1;
			Q.push(nx);
		}
	}

	cout << "use the stairs";

	return 0;

}