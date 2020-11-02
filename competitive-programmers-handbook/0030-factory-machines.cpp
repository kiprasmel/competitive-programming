#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF (1e9 + 7)

#if (0 || defined(DEBUG)) && !defined(PROD)
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

	ll n, t;
	cin >> n >> t;

	vector<ll> v(n);
	// ll max_time_unit = 0;
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
		// max_time_unit = max(max_time_unit, v[i]);
	}

	std::sort(v.begin(), v.end());

	/*
	ll work_done_after_full_cycle;
	for (ll& time_unit : v) {
		work_done_after_full_cycle += floor(max_time_unit / time_unit);
	}
	*/

	ll sum = 0;
	ll time_units_spent = 0;
	while (sum < t) {
		ll max_time_spent_so_far = 0;
		for (ll& time_unit : v) {
			sum++;
			max_time_spent_so_far = max(max_time_spent_so_far, time_unit);

			if (sum == t) {
				break;
			}
		}
		
		time_units_spent += max_time_spent_so_far;
	}

	cout << time_units_spent << "\n";

	return 0;
}

