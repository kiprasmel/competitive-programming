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

	ll curr_sum = 0;
	ll best_sum = -INF;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;

		// curr_sum = max({ 0, x, curr_sum + x }); // if empty list is allowed as an answer (effective when all numbers are negative)
		curr_sum = max(x, curr_sum + x);
		best_sum = max(best_sum, curr_sum);
	}

	cout << best_sum << "\n";

	return 0;
}

