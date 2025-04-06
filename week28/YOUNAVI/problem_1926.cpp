#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[501][501];
int visit[501][501];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	int num = 0, area = 0, tmp_area = 0;
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (board[i][j] == 1 && visit[i][j] == 0) {
				visit[i][j] = 1;
				Q.push({ i, j });
				tmp_area++;
				num++;
			}

			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visit[nx][ny] == 1 || board[nx][ny] != 1) continue;
					visit[nx][ny] = 1;
					tmp_area++;
					Q.push({ nx, ny });
				}
			}

			area = max(area, tmp_area);
			tmp_area = 0;

		}
	}
	cout << num << "\n" << area;

	return 0;

}