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

	int n;
	ll x;
	scanf("%d %lld", &n, &x);

	vector<ll> v(n + 1);
	vector<ll> psums(n + 1);
	v[0] = 0;
	psums[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);

		psums[i] = psums[i - 1] + v[i];
	}

	int left = 1, right = 1;
	ll count = 0;
	while (left <= n && right <= n) {
		ll sum = psums[right] - psums[left-1];
		LOG("left " << left << "; right " << right << "; sum " << sum);
		
		if (sum == x) {
			count++;
			left++;
		} else if (sum < x) {
			right++;
		} else if (sum > x) {
			left++;
		}
	}

	LOG("");
	printf("%lld\n", count);

	return 0;
}

