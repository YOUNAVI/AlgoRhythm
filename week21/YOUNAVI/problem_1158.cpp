#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	list<short> circle;
	list<short>::iterator p = circle.begin();

	for (int i = 1; i <= N; i++) {
		circle.insert(p, i);
	}

	cout << "<";
	p = circle.begin();
	while (circle.size() != 1) {
		for (int i = 0; i < K - 1; i++) {
			p++;
			if (p == circle.end())
				p = circle.begin();
		}
		cout << *p << ", ";
		p = circle.erase(p);
		if (p == circle.end())
			p = circle.begin();
	}
	cout << *p;
	cout << ">";

	return 0;

}
