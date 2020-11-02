// #pragma GCC optimize ("O3")
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

const ll mxN = 501;
bool ready[mxN][mxN];
ll value[mxN][mxN];
 
ll _solve(ll a, ll b) {
	LOG("a, b " << a << " " << b);
	if (ready[a][b]) {
		return value[a][b];
	}

	if (a == 0 || b == 0) {
		return 0;
	}

	if (a == b) {
		return 1;
	}

	if (a == 1) {
		return b - 1;
	}
	if (b == 1) {
		return a - 1;
	}
 
	ll ret = INF;

	for (ll j = 1; j <= b; j++) {
		for (ll i = 1; i <= a; i++) {
			// ret = min(ret, _solve(j, i) + _solve(0, i) + _solve(j, 0));
		}
	}

	// ll smaller = min(a, b);
	// ll bigger = max(a, b);

	// ll ret = min({
	// 	_solve(smaller, smaller) + _solve(bigger - smaller, smaller),
	// 	_solve(ceil(smaller / 2), bigger) + _solve(smaller - ceil(smaller / 2), bigger),
	// 	_solve(ceil(bigger / 2), smaller) + _solve(bigger - ceil(bigger / 2), smaller)
	// });

	ready[a][b] = true;
	ready[b][a] = true;
	value[a][b] = ret;
	value[b][a] = ret;

	LOG("ret " << ret);
	return ret;
}
 
ll solve(ll a, ll b) {
	// return _solve(a, b) - 1;
	return _solve(a, b);
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);
 
	ll a, b;
	cin >> a >> b;
 
	cout << solve(a, b) << "\n";
 
	return 0;
}
