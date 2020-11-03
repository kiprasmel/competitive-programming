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

ll A[5000];
bool ready[5000][5000][2];
ll memo[5000][5000][2];

ll DP(int left, int right, bool is1st, int depth) {
	ll f;

	// if (left == right) f = (is1st ? A[left] : 0);
	if (ready[left][right][is1st]) f = memo[left][right][is1st];
	else if (left == right)        f = 0;
	else {
		if (is1st) {
			f = max(
				A[left]  + DP(left + 1, right, !is1st, depth + 1),
				A[right] + DP(left, right - 1, !is1st, depth + 1)
			);
		} else {
			f = min(
				0        + DP(left + 1, right, !is1st, depth + 1),
				0        + DP(left, right - 1, !is1st, depth + 1)
			);
		}
	}

	LOG(string(depth * 2, ' ') << "left " << left << "; right " << right << "; is1st " << is1st << "; f " << f);

	ready[left][right][is1st] = true;
	memo[left][right][is1st] = f;

	return f;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &A[i]);
	}

	ll f = DP(0, n - 1, true, 0);

	printf("%lld\n", f);

	return 0;
}
