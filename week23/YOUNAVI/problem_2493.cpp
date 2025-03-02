#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Answer Code
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, tmp;
	stack<pair<int, int>> S;
	cin >> N;
	S.push({ 100000001, 0 });

	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		while (tmp > S.top().first)
			S.pop();
		cout << S.top().second << " ";
		S.push({ tmp, i });
	}

	return 0;
}

// My Code
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, tmp;
//	stack<int> S, pos;
//	cin >> N;
//
//	for(int i = 1; i <= N; i++) {
//		cin >> tmp;
//		
//		if (S.empty()) {
//			S.push(tmp);
//			pos.push(i);
//			cout << 0 << " ";
//		}
//		else if (tmp >= S.top()) {
//			while (!S.empty() && tmp >= S.top()) {
//				S.pop();
//				pos.pop();
//			}
//			if (S.empty()) cout << 0 << " ";
//			else cout << pos.top() << " ";
//			S.push(tmp);
//			pos.push(i);
//		}
//		else if (tmp < S.top()) {
//			S.push(tmp);
//			cout << pos.top() << " ";
//			pos.push(i);
//		}
//
//	}
//
//	return 0;
//
//}