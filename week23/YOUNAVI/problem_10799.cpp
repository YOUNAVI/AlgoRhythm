#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Answer Code
int main() {
	int cnt = 0, ans = 0, ch, pch;
	while ((ch = getchar()) != '\n') {
		if (ch == '(') cnt++;
		else cnt--, ans += pch == '(' ? cnt : 1;
		pch = ch;
	}
	printf("%d", ans);
}

// Simpler Code
//int main()
//{
//	stack<int> s;
//	string str;
//
//	int cnt = 0;
//	cin >> str;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == '(' && str[i + 1] == ')')
//		{
//			cnt += s.size();
//			i++;
//		}
//		else if (str[i] == '(')
//		{
//			s.push(i);
//		}
//		else if (str[i] == ')')
//		{
//			cnt++;
//			s.pop();
//		}
//	}
//	cout << cnt;
//}

// My Code
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int laser = 0, ans = 0;
//	string str;
//	cin >> str;
//	stack<char> S;
//
//	for (auto i = 0; i < str.length() - 1; i++) {
//		if (str[i] == '(' && str[i + 1] == ')') {
//			str[i] = 'l';
//			str[i + 1] = 'z';
//		}
//	}
//	
//	for (auto i : str) {
//		switch (i) {
//		case '(' :
//			ans += 1;
//			S.push(i);
//			break;
//		case ')' :
//			S.pop();
//			break;
//		case 'z' :
//			ans += S.size();
//			break;
//		}
//	}
//
//	cout << ans;
//
//	return 0;
//}