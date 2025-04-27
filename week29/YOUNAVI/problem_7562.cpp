#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[301][301];
int vis[301][301];
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;

	cin >> t;
	
	while (t--) {
		int n, x, y, target_x, target_y;
		cin >> n;
		for (int i = 0; i < 301; i++) fill(vis[i], vis[i] + 301, 0);
		queue<pair<int, int>> Q;
		
		cin >> x >> y;
		vis[x][y] = 1;
		Q.push({ x, y });

		cin >> target_x >> target_y;

		while (!Q.empty()) {
			pair<int, int> cur = Q.front();
			Q.pop();

			if (cur.first == target_x && cur.second == target_y)
				cout << vis[cur.first][cur.second] - 1 << "\n";

			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (board[nx][ny] != 0 || vis[nx][ny] > 0) continue;
				vis[nx][ny] = vis[cur.first][cur.second] + 1;
				Q.push({ nx, ny });
			}
		}

		while (!Q.empty()) Q.pop();
	}

	return 0;

}