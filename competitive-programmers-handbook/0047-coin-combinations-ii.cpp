#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = (1e9 + 7);

#if (0 || defined(DEBUG)) && !defined(EVAL)
#define LOG(x) std::cout << x << "\n"
#define LOGS(x) std::cout << x << " "
#define LO(x) std::cout << x
#define LOGA(x) for (const auto& y : x) { LOG(y); }
#define LOGSA(x) for (const auto& y : x) { LOGS(y); }
#define LOA(x) for (const auto& y : x) { LO(y); }
#else
#define LOG(x)
#define LOGS(x)
#define LO(x)
#define LOGA(x)
#define LOGSA(x)
#define LOA(x)
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll n, x;
	cin >> n >> x;

	vector<ll> v(n);
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}

	std::sort(v.begin(), v.end());

	/// number of ways to reach the current sum, up till `x`
	vector<ll> dp(x + 1, 0);

	dp[0] = 1;

	/** the main idea is to go through the coins 1st and the current sum 2nd, as opposed to the opposite */
	for (ll mi = 0; mi < n; mi++) {
		for (ll cs = 0; cs <= x; cs++) {

			ll& coin = v[mi];

			if (cs + coin <= x) {
				dp[cs + coin] = dp[cs] + dp[cs + coin];
				dp[cs + coin] %= MOD;
			}
		}
	}

	LOGSA(dp);
	LOG("");

	cout << dp[x] << "\n";

	return 0;
}

