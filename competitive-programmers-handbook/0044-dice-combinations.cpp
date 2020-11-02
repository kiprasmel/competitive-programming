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

bool ready[(ll) 1e7];
ll val[(ll) 1e7];

ll solve(ll n) {
	if (n < 0) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	if (ready[n]) {
		return val[n];
	}
	
	ll sum = 0;
	for (ll dice : { 1, 2, 3, 4, 5, 6 }) {
		sum += solve(n - dice) % INF;
	}

	ready[n] = true;
	val[n] = sum;

	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll n;
	cin >> n;

	val[0] = 0;
	ll sum = solve(n) % INF;

	cout << sum << "\n";

	return 0;
}

