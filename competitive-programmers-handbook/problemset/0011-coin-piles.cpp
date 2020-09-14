#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ull t;
	cin >> t;

	ull a, b;
	for (int tt = 0; tt < t; tt++) {
		cin >> a >> b;
		if ((a + b) % 3 == 0 && (a > b ? b >= a / 2 : a >= b / 2)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}

