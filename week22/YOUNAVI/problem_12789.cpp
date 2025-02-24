#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Answer Code
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, tmp, pos = 1;
	stack<int> space;
	cin >> N;
	
	while (N--) {
		cin >> tmp;

		if (tmp == pos)	pos++;
		else space.push(tmp);

		while (!space.empty() && space.top() == pos) {
			space.pop();
			pos++;
		}

	}

	space.empty() ? cout << "Nice" : cout << "Sad";

	return 0;

}


// My Code
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	int N, tmp, pos = 1;
//	int arr[1001];
//	fill(arr, arr + 1001, 0);
//	cin >> N;
//	stack<int> line;
//	stack<int> space;
//
//	for (int i = 0; i < N; i++) {
//		cin >> arr[i];
//	}
//
//	for (int i = N - 1; i >= 0; i--) {
//		line.push(arr[i]);
//	}
//	
//	while (pos != N + 1) {
//
//		if (!line.empty() && line.top() == pos) {
//			line.pop();
//			pos++;
//		}
//		else if (!space.empty() && space.top() == pos) {
//			space.pop();
//			pos++;
//		}
//		else {
//			if (line.empty()) break;
//			else {
//				space.push(line.top());
//				line.pop();
//			}
//		}
//	}
//
//	pos == N + 1 ? cout << "Nice" : cout << "Sad";
//
//	return 0;
//
//}