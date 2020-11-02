#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	n--;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	bool found = false;
	for (int i = 0; i < n; i++) {
		if (v[i] != i + 1) {
			cout << (i + 1) << "\n";
			found = true;
			break;
		}
	}

	if (!found) {
		cout << (n + 1);
	}

	cout << "\n";

	return 0;
}

