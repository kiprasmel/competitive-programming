#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ull n;
	cin >> n;

	ull tzcount = 0;
	ull powOf5 = 1;

	while (powOf5 <= n) {
		powOf5 *= 5;
		tzcount += floor(n / powOf5);
	}

	cout << tzcount << "\n";

	return 0;
}

