#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MOD = (1e9 + 7);

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

void test_case(ll T) {
	ll n;
	scanf("%lld", &n);

	ll prev, curr;
	scanf("%lld", &curr);

	ll pit_count = 0;

	bool possible = true;

	for (ll i = 0; i < n; i++) {
		prev = curr;
		scanf("%lld", &curr);

		if (!possible) {
			continue; // scan
		}
		
		if (pit_count == 0) {
			// shall be decreasing
			if (prev < curr) {
				pit_count++;
				continue;
			}
		}

		if (pit_count == 1) {
			// shall be increasing
			if (prev >= curr) {
				possible = false;
			}
		}
	}

	if (possible) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll t;
	scanf("%lld", &t);

	for (ll T = 0; T < t; T++) {
		test_case(T);
	}

	return 0;
}
