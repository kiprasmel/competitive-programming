#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int globalbest = 1;
	int localbest = 1;
	char c = s[0];

	for (int i = 1; i < s.length(); i++) {
		if (s[i] == c) {
			localbest++;
		} else {
			c = s[i];
			localbest = 1;
		}

		globalbest = max(globalbest, localbest);
	}

	cout << globalbest << "\n";

	return 0;
}

