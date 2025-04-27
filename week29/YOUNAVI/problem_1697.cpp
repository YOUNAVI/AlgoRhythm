#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char board[200001];	
int vis[200001];
int dx[2] = { 1, -1};

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	queue<int> Q;

	vis[n] = 0;
	Q.push(n);

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		if (cur == k) {
			cout << vis[cur];
			return 0;
		}

		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + dx[dir];
			if (nx < 0 || nx >= 100001) continue;
			if (vis[nx] > 0) continue;
			vis[nx] = vis[cur] + 1;
			Q.push(nx);
		}
		for (int dir = 0; dir < 1; dir++) {
			int nx = 2 * cur;
			if (nx < 0 || nx >= 100001) continue;
			if (vis[nx] > 0) continue;
			vis[nx] = vis[cur] + 1;
			Q.push(nx);
		}
	}

	return 0;

}