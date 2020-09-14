#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ull n;
	cin >> n;

	// 1..n
	ull sum = (n * (n + 1)) / 2;

	if (sum % 2 != 0) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	ull halfsum = sum / 2; // 14

	// 1 2 3 4 5 6 7

	/**
		simply choose from the biggest numbers up until you reach the halfsum,
		and use everything else for the other array (to get the other halfsum)
	*/

	unordered_set<ull> A;
	unordered_set<ull> B;

	/** A's goal */
	ull goal = halfsum;

	for (int i = n; i >= 1; i--) {
		if (i <= goal) {
			goal -= i;
			A.insert(i);
		} else {
			B.insert(i);
		}
	}

	cout << A.size() << "\n";
	
	for (auto x : A) {
		cout << x << " ";
	}

	cout << "\n" << B.size() << "\n";

	for (auto x : B) {
		cout << x << " ";
	}

	cout << "\n";

	return 0;
}

