#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tmp = 1, ans = 0;
	char pre = ' ';
	string str;
	stack<char> S;

	cin >> str;

	for (auto i : str) {
		if (i == '(') {
			tmp *= 2;
			S.push(i);
		}
		else if (i == '[') {
			tmp *= 3;
			S.push(i);
		}
		else if (i == ')') {
			if (S.empty() || S.top() != '(') {
				ans = 0;
				break;
			}
			else if (pre == '(') {
				ans += tmp;
				tmp /= 2;
				S.pop();
			}
			else if (pre != '(') {
				tmp /= 2;
				S.pop();
			}
		}
		else if (i == ']') {
			if (S.empty() || S.top() != '[') {
				ans = 0;
				break;
			}
			else if (pre == '[') {
				ans += tmp;
				tmp /= 3;
				S.pop();
			}
			else if (pre != '[') {
				tmp /= 3;
				S.pop();
			}
		}

		pre = i;
	}
	
	if (!S.empty()) {
		cout << 0;
		return 0;
	}

	cout << ans;

	return 0;

}