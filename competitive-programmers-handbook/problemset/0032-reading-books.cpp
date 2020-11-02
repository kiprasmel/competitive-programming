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

	ll max_num = -INF;
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		ll tmp;
		cin >> tmp;

		max_num = max(max_num, tmp);
		sum += tmp;
	}

	cout << max(sum, max_num * 2) << "\n";	

	return 0;
}

