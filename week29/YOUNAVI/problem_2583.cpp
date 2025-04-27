#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char board[1001][1001];
int vis[1001][1001];
int m, n;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int k, x1, x2, y1, y2;
	int num = 0, area = 0;
	cin >> m >> n >> k;
	queue<pair<int, int>> Q;
	vector<int> areas;

	while (k--) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				board[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			area = 0;

			if (board[i][j] == 0 && vis[i][j] == 0) {
				vis[i][j] = 1;
				Q.push({ i, j });
				num++;
			}

			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				area++;

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != 0 || vis[nx][ny] != 0) continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}

			if (area) areas.push_back(area);
		}
	}

	cout << num << "\n";
	sort(areas.begin(), areas.end());
	for (auto x : areas) cout << x << " ";

	return 0;
}