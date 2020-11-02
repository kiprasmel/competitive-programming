#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long sum = 0;

	long long prev = 0;
	long long curr;
	for (int i = 0; i < n; i++) {
		cin >> curr;

		if (curr < prev) {
			sum += prev - curr;
		} else {
			prev = curr;
		}
		
	}

	cout << sum << "\n";

	return 0;
}

