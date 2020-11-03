#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF (1e9 + 7)

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

	ll t;
	cin >> t;

	for (ll tt = 0; tt < t; tt++) {
		ll n, m;
		cin >> n >> m;

		ll x = n * m;

		vector<ll> v(x);
		ll sum = 0;
		for (ll i = 0; i < x; i++) {
			cin >> v[i];
			sum += v[i];
		}

		std::sort(v.begin(), v.end());

		ll med = x % 2 == 0
			? (v[x / 2 - 1] + v[x / 2]) / 2
			: (v[x / 2]               ) / 2
		;

		ll ops = 0;
		for (ll i = 0; i < x; i++) {
			ops += std::abs(v[i] - med);
		}

		cout << ops << "\n";
	}

	return 0;
}

