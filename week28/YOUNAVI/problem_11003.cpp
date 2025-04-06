#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, L, tmp;
	cin >> N >> L;
	deque<pair<int, int>> d;	

	for (int i = 0; i < N; i++) {
		cin >> tmp;

		while (!d.empty() && d.back().first > tmp) {
			d.pop_back();
		}

		d.push_back({ tmp, i });
		
		if (d.front().second <= i - L) {
			d.pop_front();
		}

		cout << d.front().first << " ";
	}

	return 0;

}