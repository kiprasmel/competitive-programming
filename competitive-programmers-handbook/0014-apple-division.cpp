#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#if (0 || defined(DEBUG)) && !defined(PROD)
#define LOG(x) std::cout << x << "\n"
#define LOGS(x) std::cout << x << " "
#else
#define LOG(x)
#define LOGS(x)
#endif

ll backtrack(const vector<ll>& v, ll min_idx, ll sum_a, ll sum_b) {
	LOG("min_idx " << min_idx << "; sum_a " << sum_a << "; sum_b " << sum_b);

	if (min_idx == v.size()) {
		return std::abs(sum_a - sum_b);
	}

	return min(
		backtrack(v, min_idx + 1, sum_a + v[min_idx], sum_b),
		backtrack(v, min_idx + 1, sum_a, sum_b + v[min_idx])
	);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);

	ll n;
	cin >> n;

	vector<ll> v(n);
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}

	cout << backtrack(v, 0, 0, 0) << "\n";

	return 0;
}
