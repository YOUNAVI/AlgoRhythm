#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void emptyStack(stack<char> &s);
int main()
{
    stack<char> stack;
    string str;
    getline(cin, str);
    for (int i = 0;i < str.size();i++)
    {
        if (str[i] == '<')
        {
            emptyStack(stack);
            while (1)
            {
                cout << str[i];
                if (str[i] == '>')
                    break;
                i++;
            }
        }
        else if (str[i] == ' ')
        {
            emptyStack(stack);
            cout << " ";
        }
        else
        {
            stack.push(str[i]);
        }
    }
    emptyStack(stack);
}

// My code
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	string S;
//  stack<char> str; 
//	bool tagInside = true;
//	getline(cin, S);
//
//	for (auto i : S) {
//
//		if (tagInside && (i == ' ' || i == '<')) {
//			emptyStack(str);
//			cout << i;
//			if (i == '<') tagInside = false;
//			}
//		else if (tagInside) str.push(i);
//		else if (!tagInside) cout << i;
//		
//		if (i == '>')
//			tagInside = true;
//
//	}
//	emptyStack(str);
//
//	return 0;
//
//}

void emptyStack(stack<char> &s) {
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}