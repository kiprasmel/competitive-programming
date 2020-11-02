#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned long long n;
	cin >> n;

	unsigned long long lastAccel = 0;

	// cout << "k" << "\t\t" << "doublemaxavail" << "\t" << "maxavail" << "\t" << "acceleration" << "\t" << "unavailable" << "\t" << "ans" << "\n";

	for (unsigned long long k = 1; k <= n; k++) {
		if (k == 1) {
			cout << 0 << "\n";
			continue;
		}

		/**
		  * figured out with some combinatorics, graph theory (directed vs undirected)
		  * & experimentation with the sample example until I found the acceleration part
		 */

		unsigned long long sq = k * k;
		unsigned long long doublemaxavail = sq * (sq - 1); /** later to be divided by 2 because which knight it doesn't matter */
		unsigned long long maxavail = doublemaxavail / 2;

		unsigned long long acceleration = k - 2 + lastAccel;

		unsigned long long unavailable = acceleration * 8;

		unsigned long long ans = maxavail - unavailable;

		cout << ans << "\n";
		// cout << k << "\t\t" << doublemaxavail << "\t\t" << maxavail << "\t\t" << acceleration << "\t\t" << unavailable << "\t\t" << ans << "\n";

		lastAccel = acceleration;
	}

	return 0;
}

