#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, tmp;
	stack<pair<int,int>> S;
	cin >> N;
	
	for(int i = 0; i < N; i++) {
		cin >> tmp;

		if (S.empty()) {
			S.push({ tmp, i });
			continue;
		}

		while (!S.empty() && tmp > S.top().first) {
			arr[S.top().second] = tmp;
			S.pop();	
		}

		S.push({ tmp, i });

	}

	while (!S.empty()) {
		arr[S.top().second] = -1;
		S.pop();
	}

	for (int i = 0; i < N; i ++) {
		cout << arr[i] << " ";
	}

	return 0;

}