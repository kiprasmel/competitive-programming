#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ull n;
	cin >> n;

	// ull ans = ull (1 << n) % ull (1e9 + 7);

	ull ans = 1;

	for (int i = 0; i < n; i++) {
		ans = (ans * 2) % ull (1e9 + 7);
	}

	cout << ans << "\n";

	return 0;
}

