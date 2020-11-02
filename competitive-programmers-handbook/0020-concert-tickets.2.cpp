#include <algorithm>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int n, m;
	scanf("%d %d", &n, &m);

	vector<ll> t(n)/*, c(m)*/;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &t[i]);
	}

	/*
	for (int i = 0; i < m; i++) {
		scanf("%lld", &c[i]);
	}
	*/

	std::sort(t.begin(), t.end());

	std::stringstream ss;

	for (int i = 0; i < m; i++) {
		if (!t.size()) {
			// printf("%d\n", -1);
			ss << "-1\n";
			continue;
		}

		ll max_price;
		scanf("%lld", &max_price);

		/*
		vector<ll>::iterator offer = std::lower_bound(t.begin(), t.end(), max_price);

		if (offer == t.end()) {
			offer--;
		}
		*/
		vector<ll>::iterator offer = std::upper_bound(t.begin(), t.end(), max_price);

		if (offer != t.begin()) {
			offer--;
		}

		if (*offer > max_price && offer != t.begin()) {
			offer--;
		}

		if (offer == t.begin() && *offer > max_price) {
			// printf("%d\n", -1);
			ss << "-1\n";
		} else {
			// printf("%lld\n", *offer);
			ss << *offer << "\n";
			t.erase(offer);
		}
	}

	cout << ss.str();

	return 0;
}

