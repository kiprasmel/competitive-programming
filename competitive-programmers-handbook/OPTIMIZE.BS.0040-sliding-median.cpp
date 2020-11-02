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

	ll n, k;
	cin >> n >> k;

	vector<ll> v(n);
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (ll i = 0; i < n - k + 1; i++) {
		vector<ll> sub(v.begin() + i, v.begin() + i + k); /* BAD! takes by reference instead of copying */
		std::sort(sub.begin(), sub.end()); /** must sort only this sub-part */

		for (ll& s : sub) {
			LOGS(s);
		}
		LOG("");

		ll med;
		if (k % 2 == 0) {
			// med = (sub[k / 2 + i - 1] + sub[k / 2 + i]) / 2;
			med = (sub[k / 2 - 1] + sub[k / 2]) / 2;
		} else {
			// med = sub[k / 2 + i];
			med = sub[k / 2];
		}

		cout << med << " ";
		LOG("");
	}

	return 0;
}

