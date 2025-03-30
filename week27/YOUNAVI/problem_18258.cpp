#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n, s, e;
int q[2000005];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> n;
	
	while (n--) {
		cin >> str;

		if (str == "push")
			cin >> q[e++];	
		else if (str == "pop")
			cout << (s == e ? -1 : q[s++]) << "\n";
		else if (str == "size")
			cout << e - s << "\n";
		else if (str == "empty")
			cout << (s == e) << "\n";
		else if (str == "front")
			cout << (s == e ? -1 : q[s]) << "\n";
		else if (str == "back")
			cout << (s == e ? -1 : q[e-1]) << "\n";
	}

	return 0;

}