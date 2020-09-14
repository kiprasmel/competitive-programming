#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long n;
	cin >> n;	

	while (n != 1) {
		cout << n << " ";
		n % 2 == 0
			? n /= 2
			: n = n * 3 + 1;
	}

	cout << (1) << "\n";

	return 0;
}

