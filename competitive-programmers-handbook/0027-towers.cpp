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
	
	vector<ll> towers; // always stays sorted from smallest to largest (push_back & problem's rules/behavior)
	ll biggest_tower = -INF;
	for (ll i = 0; i < n; i++) {
		ll cube;
		cin >> cube;

		if (cube >= biggest_tower) {
			towers.push_back(cube);
			biggest_tower = cube;
		} else {
			auto it = std::upper_bound(towers.begin(), towers.end(), cube); // we're always trying to have the biggest possible towers to avoid creating new ones, thus replacing a bigger with a smaller one is most efficient when the difference between them is the smallest, thus upper_bound fits in perfectly
			ll pos = it - towers.begin();

			towers[pos] = cube;
			biggest_tower = towers[towers.size() - 1];
		}
	}

	cout << towers.size() << "\n";

	return 0;
}
