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

	ll n;
	cin >> n;

	vector<ll> v(n);
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}

	ll q;
	cin >> q;

	ll l = 0, r = 0;
	ll last = 0;

	for (ll i = 0; i < q; i++) {
		ll x, y;
		cin >> x >> y;

		l = (last + x) % n + 1;
		r = (last + y) % n + 1;

		if (l > r) {
			ll tmp = l;
			l = r;
			r = tmp;
		}

		// printf("l %d, r %d, v[l] %d, v[r] %d \n", l, r, v[l-1], v[r-1]);

		last = (ll) v[l-1] % (ll) INF;
		for (ll j = l; j < r && j < n; j++) {
			LOG("lcm of " << last << " and " << v[j]);
			last = (ll) std::lcm(last, v[j]) % (ll) INF;
		}
		LOG("");

		cout << last << "\n";
	}

	return 0;
}

