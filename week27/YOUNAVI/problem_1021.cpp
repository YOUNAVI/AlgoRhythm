#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, tmp, ans = 0;
	deque<int> DQ;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)
		DQ.push_back(i);

	while (M--) {
		cin >> tmp;
		int idx = find(DQ.begin(), DQ.end(), tmp) - DQ.begin();
		if (idx <= DQ.size() / 2) {
			while (DQ.front() != tmp) {
				DQ.push_back(DQ.front());
				DQ.pop_front();
				ans++;
			}
		}
		else {
			while (DQ.front() != tmp) {
				DQ.push_front(DQ.back());
				DQ.pop_back();
				ans++;
			}
		}
		DQ.pop_front();
	}

	cout << ans;

	return 0;
	
}