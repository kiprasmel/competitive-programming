#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = (1e9 + 7);
const ll INFx2 = INF * 2;

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

bool ready[125250][500];
ll value[125250][500];

// const ll mxN = 500 * 501 / 2 + 1;
// ll solve(const ll& n, const ll begin, const ll halfsum) {
ll solve(ll begin, const ll n, ll halfsum) {
	LOG("begin, n, halfsum = \t" << begin << ";\t" << n << ";\t" << halfsum);

	if (halfsum < 0) {
		return 0;
	}
	if (halfsum == 0) {
		return 1;
	}
	if (ready[halfsum][begin]) {
		return value[halfsum][begin];
	}

	ll sum = 0;
	for (ll i = begin; i <= n; i++) {
		ll ret = solve(i + 1, n, halfsum - i);
		sum += ret;
		sum %= INFx2;

		/*
		if (ret == 0) {
			break;
		}
		*/
	}

	ready[halfsum][begin] = true;
	value[halfsum][begin] = sum;

	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll n;
	cin >> n;

	ll sum = n * (n + 1) / 2;
	ll half = sum / 2;

	LOG("\n n " << n
	 << "\n sum " << sum 
	 << "\nhalf " << half
	 );

	if (sum % 2 != 0) {
		cout << 0 << "\n";
		return 0;
	}
	
	int dp[501 * 502 / 2];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for (int x = n; x >= 1; x--) {
		for (int i = n * n / 2; i >= 0; i--) {
			if (dp[i]) {
				dp[i + x] += dp[i] + 1;
				dp[i + x] %= INF;
			}
		}
	}

	LOGSA(dp);
	LOG("");

	int sol = dp[half];

	/*
	ll sol = solve(1, n, half);

	LOG("orig sol without (/ 2) & (% INF) = " << sol);

	// assert(sol % 2 == 0);
	// the solution count is always 2x because they're mirrored -- we fix it here
	sol /= 2;
	sol %= INF;
	*/

	cout << sol << "\n";

	return 0;
}

