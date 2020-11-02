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

	ll n;
	cin >> n;

	vector<ll> v(n);
	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}

	/*

10
2 2 1 1 2 1 2 1 2 1

8
1 2 1 3 2 7 4 2
0 1 2 3 4 5 6 7 8 9
	*/

	map<ll, ll> m; // num -> ~~how many unique items has since last duplicate~~ latest index (last uniq idx)
	ll longest_uniq_seq = 0, best_longest_uniq_seq = 0;
	ll earliest_uniq_idx = 0;
	for (ll i = 0; i < n; i++) {
		ll& num = v[i];

		if (m.count(num) == 0) {
			longest_uniq_seq++;
		} else {
			// longest_uniq_seq -= m[num] - last_uniq_idx;
			longest_uniq_seq = i - earliest_uniq_idx; //  m[num];
			// earliest_uniq_idx = i;
			ll dup_item = num; // v[earliest_uniq_idx];

			while (v[++earliest_uniq_idx] == dup_item && earliest_uniq_idx < i) {
			}

			// do {
			// 	++earliest_uniq_idx;
			// } while (v[earliest_uniq_idx] == dup_item && earliest_uniq_idx < i);
		}
		
		m[num] = i;

		best_longest_uniq_seq = max(best_longest_uniq_seq, longest_uniq_seq);
	}

	cout << best_longest_uniq_seq << "\n";

	return 0;
}
