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

	ll t;
	cin >> t;
	
	while (t--) {
		ll n;
		cin >> n;

		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}
		if (n == 2) {
			cout << 2 << "\n"
				 << 1 << " " << 2 << "\n";
			continue;
		}

		ll last = n;
		// // for (ll i = n; i >= 0; i--) {
		ll i = n;
		ll even_idx = n % 2 == 0 ? n - 2 : n - 1;
		ll  odd_idx = n % 2 == 0 ? n - 1 : n - 2;

		vector<pair<ll, ll>> v;

		ll prev_i = -1;
		while (i > 0) {
			if (i == prev_i) {
				break;
			}
			prev_i = i;

			if (last % 2 == 0 && even_idx >= 1) {
				v.push_back({ even_idx, last });

				last = (last + even_idx) / 2;
				even_idx -= 2;
				i--;
			}
			else if (last % 2 != 0 && odd_idx >= 1) {
				v.push_back({ last, odd_idx });

				last = (last + odd_idx) / 2;
				odd_idx -= 2;
				i--;
			}

			/*
			if (i >= 2) {
				last = (last + (i - 2)) / 2;
				last = (last + (i - 1)) / 2;
				i -= 2;
			}

			if (i >= 1) {
				last = (last + (i - 1)) / 2;
				i--;
			}

			i--;
			*/
		}

		cout << last << "\n";

		for (auto p : v) {
			cout << p.first << " " << p.second << "\n";
		}

	}

	return 0;
}

