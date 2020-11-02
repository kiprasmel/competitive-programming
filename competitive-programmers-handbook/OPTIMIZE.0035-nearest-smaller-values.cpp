#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF (1e9 + 7)

#if (0 || defined(DEBUG)) && !defined(PROD)
#define LOG(x) std::cout << x << "\n"
#define LOGS(x) std::cout << x << " "
#define LO(x) std::cout << x
#else
#define LOG(x)
#define LOGS(x)
#define LO(x)
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("in", "r", stdin); std::ifstream __input_file("in"); assert(__input_file.good());
	// freopen("out", "w", stdout);

	ll n;
	cin >> n;

	vector<ll> v(n);
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}

	ll min_so_far = INF;
	for (ll i = 0; i < v.size(); i++) {
		if (v[i] <= min_so_far) {
			cout << 0 << " ";
			min_so_far = min(min_so_far, v[i]);
			continue;
		}

		bool found = false;
		for (ll j = i - 1; j >= 0; j--) {
			if (v[j] < v[i]) {
				found = true;
				cout << (j + 1) << " ";
				break;
			}
		}

		if (!found) {
			cout << 0 << " ";
		}

		min_so_far = min(min_so_far, v[i]);
	}

	return 0;
}

