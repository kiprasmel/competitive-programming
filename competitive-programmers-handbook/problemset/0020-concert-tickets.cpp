#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#if (1 || defined(DEBUG)) && !defined(PROD)
#define LOG(x) std::cout << x << "\n"
#define LOGS(x) std::cout << x << " "
#define LO(x) std::cout << x
#else
#define LOG(x)
#define LOGS(x)
#define LO(x)
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("in", "r", stdin); std::ifstream __input_file("in"); assert(__input_file.good());
	// freopen("out", "w", stdout);

	ll n, m;
	cin >> n >> m;

	vector<ll> t(n);
	vector<bool> taken(n, false);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}

	vector<ll> c(m);
	for (int i = 0; i < m; i++) {
		cin >> c[i];
	}

	std::sort(t.begin(), t.end());

	for (auto& max_price : c) {
		ll best_match = 0;
		ll best_match_idx = -1;

		ll start = 0, end = t.size() - 1;
		
		ll added_to_start = 0;
		while (start <= end) {
			ll mid = (start + end) / 2;
				
			if (taken[mid]) {
				start++;
				added_to_start++;
				continue;
			}

			if (t[mid] <= max_price) {
				start = mid + 1;

				if (t[mid] > best_match) {
					best_match = t[mid];
					best_match_idx = mid;
				}
			} else {
				end = mid - 1;
				start -= added_to_start;
			}
		}

		if (best_match_idx == -1) {
			cout << "-1\n";
		} else {
			taken[best_match_idx] = true;
			cout << best_match << "\n";
		}
	}

	return 0;
}
