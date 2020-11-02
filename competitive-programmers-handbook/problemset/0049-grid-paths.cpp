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

	vector<vector<ll>> v(n, vector<ll>(n, 0));

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			char tmp;
			cin >> tmp;
			v[i][j] = (tmp == '.' ? 1 : 0);

			if (i == 0 && j > 0 && v[0][j - 1] == 0) {
				v[0][j] = 0;
			}
			if (j == 0 && i > 0 && v[i - 1][0] == 0) {
				v[i][0] = 0;
			}
		}
	}

	if (v[0][0] == 0) {
		cout << 0 << "\n";
		return 0;
	}

	for (ll i = 1; i < n; i++) {
		for (ll j = 1; j < n; j++) {
			if (v[i][j] == 0) {
				continue;
			}

			v[i][j] = v[i - 1][j] + v[i][j - 1];
			v[i][j] %= INF;
		}
	}

	for (ll i = 0; i < n; i++) {
		LOGSA(v[i]);
		LOG("");
	}
	LOG("");

	cout << v[n - 1][n - 1] << "\n";

	return 0;
}

