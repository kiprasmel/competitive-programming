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
#define LOGA(x) for (const auto& y : x) { LOG(y); } cout << "\n";
#define LOGSA(x) for (const auto& y : x) { LOGS(y); } cout << "\n\n";
#define LOA(x) for (const auto& y : x) { LO(y); } cout << "\n\n"
#else
#define LOG(x)
#define LOGS(x)
#define LO(x)
#define LOGA(x)
#define LOGSA(x)
#define LOA(x)
#endif

void test_case() {
	ll n;
	cin >> n;

	vector<ll> v(n * 2);

	for (ll i = 0; i < n * 2; i++) {
		char c;
		cin >> c;

		if (c == '+') {
			v[i] = 0;
		} else /* - */ {
			cin >> v[i];
		}
	}

	ll num_placed = 0;
	ll num_avail = 0;
	ll cheapest_placed = INF;
	// ll cheapest_bought = INF;
	for (ll i = 0; i < n * 2; i++) {
		ll& x = v[i];

		if (x == 0) /* + */ {
			num_placed++;
			num_avail++;
		} else /* - */ {

			if (num_avail > 0) {
				num_avail--;
			} else {
				cout << "NO\n";
				return;
			}

			if (x > cheapest_placed) {
				cout << "NO\n";
				return;
			}
		}

		cheapest_placed = min({
			cheapest_placed,
			n - num_placed + 1,
			x
		});
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	test_case();

	return 0;
}

