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

	ll n;
	cin >> n;

	vector<ll> nums(n);
	for (ll i = 0; i < n; i++) {
		cin >> nums[i];
	}

	vector<ll> length(n, 1);

	ll max_len = 1;
	for (ll i = 1; i <= n; i++) {

		for (ll x = 0; x < i; x++) {
			if (nums[x] < nums[i]) {
				length[i] = max(length[i], length[x] + 1);
				max_len = max(max_len, length[i]);
			}
		}
	}

	LOGSA(length);

	cout << max_len << "\n";

	return 0;
}

