#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int board[26][26];
int vis[26][26];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string tmp;
	vector<int> areas;
	queue<pair<int, int>> Q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int j = 0;
		cin >> tmp;
		for (auto x : tmp) {
			board[i][j] = x - '0';
			j++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			int area = 0;

			if (board[i][j] == 1 && vis[i][j] == 0) {
				vis[i][j] = 1;
				Q.push({ i, j });
			}

			while (!Q.empty()) {
				pair<int, int> cur = Q.front();
				Q.pop();
				area++;

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] != 1 || vis[nx][ny] != 0) continue;
					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}

			if (area != 0) areas.push_back(area);
		}
	}
	
	sort(areas.begin(), areas.end());

	cout << areas.size() << "\n";
	for (auto x : areas) cout << x << "\n";
	
	return 0;

}