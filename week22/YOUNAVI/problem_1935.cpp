#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string calc;
	stack<double> S;
	double a, b, ans = 0;
	int n;
	double arr[26];
	fill(arr, arr + 26, 0);
	cin >> n;
	cin >> calc;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	for (auto i : calc) {
		switch (i) {
		case '+':
			b = S.top();
			S.pop();
			a = S.top();
			S.pop();
			S.push(a + b);
			break;

		case '-':
			b = S.top();
			S.pop();
			a = S.top();
			S.pop();
			S.push(a - b);
			break;

		case '*':
			b = S.top();
			S.pop();
			a = S.top();
			S.pop();
			S.push(a * b);
			break;

		case '/':
			b = S.top();
			S.pop();
			a = S.top();
			S.pop();
			S.push(a / b);
			break;

		default:
			S.push(arr[i - 'A']);
			break;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << S.top();

	return 0;

}