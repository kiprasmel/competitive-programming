#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = (1e9 + 7);

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

	ll a, b;
	cin >> a >> b;

	vector<vector<ll>> dp (b, vector<ll>(a, INF));

	dp[0][0] = 1;

	for (ll y = 1; y < b; y++) {
		for (ll x = 1; x < a; x++) {
			if (x == y) {
				dp[y][x] = 0;
				continue;
			}

			

			dp[y][x] = min({ dp[y][x], dp[y - 1][x] + 1, dp[y][x - 1] + 1, dp[y - 1][x - 1] + 1 });
		}
	}

	for (auto v : dp) {
		LOGSA(v);
		LOG("");
	}
	LOG("");

	cout << dp[a][b] - 1 << "\n";	

	return 0;
}

