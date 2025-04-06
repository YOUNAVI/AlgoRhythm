#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char board[1001][1001];
int vis[1001][1001];
int fire[1001][1001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 1001; i++) {
		fill(board[i], board[i] + 1001, '#');
	}

	int n, m, s, ans = 1001;
	string tmp;
	queue<pair<int, int>> Q;
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		cin >> tmp;
		int j = 0;
		for (auto x : tmp) {
			board[i][j] = x;
			j++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				fire[i][j] = 1;
				Q.push({ i, j });
			}
		}
	}

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (fire[nx][ny] != 0 || board[nx][ny] != '.') continue;
			fire[nx][ny] = fire[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}
	}

	while (!Q.empty()) Q.pop();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'J') {
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
					cout << 1;
					return 0;
				}
				vis[i][j] = 1;
				Q.push({ i, j });
			}
		}
	}

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << vis[cur.first][cur.second];
				return 0;
			};
			if (vis[nx][ny] != 0 || board[nx][ny] != '.') continue;
			if (vis[cur.first][cur.second] + 1 >= fire[nx][ny] && fire[nx][ny] > 0) continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			
			Q.push({ nx, ny });
		}

	}

	cout << "IMPOSSIBLE";

	return 0;

}