#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 1) {
		cout << 1 << "\n";
		return 0;
	}
	if (n == 2 || n == 3) {
		cout << "NO SOLUTION\n";
		return 0;
	}

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}

	int tries = 0;
	while (true) {
		tries++;
		random_shuffle(v.begin(), v.end());

		bool succ = true;

		// cout << "\n";
		int last = 0;
		for (auto x : v) {
			// cout << x << " ";
			if (abs(x - last) > 1) {
				last = x;
				continue;
			} else { 
				succ = false;
				break;
			}
		}

		if (succ) {
			//cout << "\n\nDONE (" << tries << ")\n\n";
			for (auto x : v) {
				cout << x << " ";
			}
			cout << "\n";
			return 0;
		} 
	}

	return 0;
}

