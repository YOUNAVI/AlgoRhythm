#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[101][101];
int vis[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	string tmp;
	cin >> n >> m;
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		int j = 0;
		for (auto x : tmp) {
			board[i][j] = x - '0';
			j++;
		}
	}

	vis[0][0] = 1;
	Q.push({ 0, 0 });

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] > 0 || board[nx][ny] != 1) continue;
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
			Q.push({ nx, ny });
		}
	}

	cout << vis[n - 1][m - 1];

	return 0;

}