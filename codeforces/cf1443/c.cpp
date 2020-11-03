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

ll DP(ll n, const vector<ll> A, const vector<ll> B) {
	if (n < 0) return 0;
	else if (n == 0) return min(A[0], B[0]);
	else {
		ll prev = DP(n - 1, A, B);

		ll a = max(prev, A[n - 1]);
		ll b = prev + B[n - 1];

		// LOGSA(A);
		// LOGSA(B);
		// LOG("n " << n << "; a " << a << "; b " << b);
		printf("a %lld; b %lld; n %lld; A[n-1] %lld; B[n-1] %lld; \n", a, b, n, A[n-1], B[n-1]);

		return min(
			a, b
			
		);
	}
}

void test_case(ll T) {
	ll n;
	scanf("%lld", &n);

	vector<ll> A(n), B(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &A[n]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld", &B[n]);
	}

	ll ans = DP(n, A, B);
	printf("%lld\n", ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll T;
	scanf("%lld", &T);

	while (T--) {
		test_case(T);
	}

	return 0;
}
