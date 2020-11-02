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

	ll n, x;
	cin >> n >> x;

	vector<ll> c(n);
	for (ll i = 0; i < n; i++) {
		cin >> c[i];
	}

	vector<ll> coins_needed(x + 1); /** to form a sum of [i] */

	coins_needed[0] = 0;
	for (ll i = 1; i <= x; i++) {
		coins_needed[i] = INF;
		for (ll coin : c) {
			if (i - coin >= 0) {
				coins_needed[i] = min(coins_needed[i], coins_needed[i - coin] + 1);
			}
		}
	}

	cout << (coins_needed[x] == INF ? -1 : coins_needed[x]) << "\n";

	return 0;
}
