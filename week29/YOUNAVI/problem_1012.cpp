#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, n, m, k, i, j;
	cin >> t;

	int dx[4] = { 1, 0 , -1, 0 };
	int dy[4] = { 0, 1 , 0, -1 };

	while (t--) {

		int board[51][51];
		int vis[51][51];
		for (int i = 0; i < 51; i++) {
			fill(board[i], board[i] + 51, 0);
			fill(vis[i], vis[i] + 51, 0);
		}
		queue<pair<int, int>> Q;
		int ans = 0;
		cin >> n >> m >> k;
		
		while (k--) {
			cin >> i >> j;
			board[i][j] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (board[i][j] == 1 && vis[i][j] == 0) {
					vis[i][j] = 1;
					Q.push({ i, j });
					ans++;
				}

				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (board[nx][ny] != 1 || vis[nx][ny] == 1) continue;
						vis[nx][ny] = 1;
						Q.push({ nx, ny });
					}
				}
			}
		}

		cout << ans << "\n";

	}

	return 0;

}