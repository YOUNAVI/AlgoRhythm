#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {

		string tmp;
		cin >> tmp;
		list<char> keylog;
		list<char>::iterator cursor = keylog.begin();

		for (auto k : tmp) {
			switch (k) {
			case '<':
				if (cursor != keylog.begin())
					cursor--;
				break;
			case '>':
				if (cursor != keylog.end())
					cursor++;
				break;
			case '-':
				if (cursor != keylog.begin()) {
					cursor--;
					cursor = keylog.erase(cursor);
				}
				break;
			default:
				keylog.insert(cursor, k);
				break;
			}
		}

		for (auto c : keylog) cout << c;
		cout << "\n";

	}

	return 0;

}
