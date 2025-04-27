#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char board[101][101];
int vis[101][101];
int n;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int blind = 0, nonBlind = 0;
	string tmp;
	queue<pair<int, int>> Q;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		int j = 0;
		for (auto x : tmp) {
			board[i][j] = x;
			j++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				vis[i][j] = 1;
				Q.push({ i, j });
				nonBlind++;
			}
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != board[cur.first][cur.second] || vis[nx][ny] != 0) continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
		}
	}

	for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				vis[i][j] = 1;
				Q.push({ i, j });
				blind++;
			}
			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != board[cur.first][cur.second] || vis[nx][ny] != 0) continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
		}
	}

	cout << nonBlind << " " << blind;

	return 0;

}