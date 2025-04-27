#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[101][101][101];
int vis[101][101][101];
int n, m, h;
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1};

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			fill(board[i][j], board[i][j] + 101, -1);
		}
	}

	int ans = 0;
	queue<tuple<int, int, int>> Q;
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (board[i][j][k] == 1) {
					vis[i][j][k] = 0;
					Q.push({ i, j, k });
				}
			}
		}
	}

	while (!Q.empty()) {
		tuple<int, int, int> cur = Q.front();
		Q.pop();
		ans = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)];

		for (int dir = 0; dir < 6; dir++) {
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>(cur) + dz[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
			if (board[nx][ny][nz] != 0 || vis[nx][ny][nz] > 0) continue;
			board[nx][ny][nz] = 1;
			vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Q.push({ nx, ny, nz });
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (board[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << ans;

	return 0;

}