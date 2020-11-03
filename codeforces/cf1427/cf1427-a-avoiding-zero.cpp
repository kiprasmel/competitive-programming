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

bool backtrack(const vector<ll> v, vector<bool> v_idx_taken, vector<ll> used, ll sum) {
	if (used.size() == v.size()) {
		cout << "YES\n";

		for (auto u : used) {
			// cout << (v[used[u] - 1]) << " ";
			cout << (v[u]) << " ";
		}

		cout << "\n";

		return true;
	}

	bool done = false;

	for (ll i = 0; i < v.size(); i++) {
		if (v_idx_taken[i]) {
			continue;
		}

		if (sum + v[i] != 0) {
			used.push_back(i);
			v_idx_taken[i] = true;

			bool res = backtrack(v, v_idx_taken, used, sum + v[i]);

			v_idx_taken[i] = false;
			used.pop_back();

			if (res) {
				done = true;
				break;
			}
		}
	}

	return done;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;

		vector<ll> v(n);
		for (ll i = 0; i < n; i++) {
			cin >> v[i];
		}
		
		vector<bool> v_idx_taken(n, false);
		vector<ll> used;

		bool res = backtrack(v, v_idx_taken, used, 0);

		if (!res) {
			cout << "NO\n";
		}

		v.clear();
		v_idx_taken.clear();
		used.clear();
	}

	return 0;
}

