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
#define LOGSA(x) for (const auto& y : x) { LOGS(y); }; LOG("")
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

	ll n, X;
	cin >> n >> X;

	vector<ll> prices(n), pages(n);
	for (ll i = 0; i < n; i++) {
		cin >> prices[i];
	}
	for (ll i = 0; i < n; i++) {
		cin >> pages[i];
	}

	vector<ll> max_pages(X);
	max_pages[0] = 0;

	ll best_max_pages = 0;

	vector<ll> required_price(X);
	required_price[0] = 0;

	vector<ll> bought(X);

	for (ll x = 1; x <= X; x++) {
		for (ll i = 0; i < n; i++) {
			// if (x - prices[i] >= 0 && x + (x - prices[i]) <= X) {
			if (
					x - prices[i] >= 0
					&& max_pages[x - prices[i]] + pages[i] >= max_pages[x]
					&& required_price[x - prices[i]] + prices[i] <= X
					// && (!bought[x] || bought[x - prices[i]] + prices[i] <= bought[x])
				) {
				// max_pages[x] = max(max_pages[x], max_pages[x - prices[i]] + pages[i]);
				max_pages[x] = max_pages[x - prices[i]] + pages[i];
				best_max_pages = max(best_max_pages, max_pages[x]);

				// required_price[x] = required_price[x - prices[i]] + prices[i];
				// required_price[x] = min(required_price[x], required_price[x - prices[i]] + prices[i]);
				required_price[x] = max(required_price[x], required_price[x - prices[i]] + prices[i]);
				//bought[i] = true;

				bought[x] = prices[i];
			}
		}
	}
	
	LOG("max_pages:");
	LOGSA(max_pages);

	LOG("required_price:");
	LOGSA(required_price);

	LOG("bought all:");
	LOGSA(bought);

	LOG("bought:");
	while (X > 0 && bought[X] > 0) {
		LOGS(bought[X]);
		X -= bought[X];
	}

	LOG("\nbest:");
	cout << best_max_pages << "\n";

	return 0;
}

