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

struct Val {
	ll val;
	int oidx;

	bool operator< (const Val& other) {
		return val < other.val;
	}

	bool operator< (const ll& other) {
		return val < other;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int n;
	scanf("%d", &n);

	vector<ll> v(n);
	// vector<Val> vs(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);

		/*
		vs[i].val = v[i];
		vs[i].oidx = i;
		*/
	}

	/*
	std::sort(vs.begin(), vs.end());

	for (int i = 0; i < n; i++) {
		vector<Val>::iterator it = std::lower_bound(vs.begin(), vs.end(), v[i]);

		// if (it != vs.begin()) {
		// 	it--;
		// } else {
		// 	printf("0 ");
		// 	continue;
		// }

		while ((it->oidx >= i || it->val >= v[i]) && it != vs.begin()) {
			it--;
		}

		if (it->oidx >= i || it->val >= v[i]) {
			printf("0 ");
		} else {
			printf("%d ", it->oidx + 1);
		}
	}
	*/

	ll min_so_far = 1e9 + 7;
	bool is_sorted_so_far = true;
	ll diff = 0;
	for (int i = 0; i < n; i++) {
		bool found = false;

		/// mayb earlier build ranges for binary searching with comparison fns ready?...
		if (i == 1) {
			diff = v[1] - v[1-0];
		}
		if (is_sorted_so_far && i >= 1 && v[i]

		if (min_so_far >= v[i]) {
			printf("0 ");
			min_so_far = min(min_so_far, v[i]);
			continue;
		}
		min_so_far = min(min_so_far, v[i]);

		for (int j = i - 1; j >= 0; j--) {
			if (v[j] < v[i]) {
				found = true;
				printf("%d ", j + 1);
				break;
			}
		}
		
		if (!found) {
			printf("0 ");
		}
	}

	return 0;
}

