#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#if (0 || defined(DEBUG)) && !defined(PROD)
#define LOG(x) std::cout << x << "\n"
#define LOGS(x) std::cout << x << " "
#define LO(x) std::cout << x
#else
#define LOG(x)
#define LOGS(x)
#define LO(x)
#endif

struct Val {
	ll val;

	/** BS #1 (sorting loses the original index so this is a work-around) */
	ll orig_idx;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("in", "r", stdin); std::ifstream __input_file("in"); assert(__input_file.good());
	// freopen("out", "w", stdout);

	ll n, x;
	cin >> n >> x;	

	/** BS #2 (caused by invalid input) */
	if (n < 2) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	vector<Val> v(n);

	for (ll i = 0; i < n; i++) {
		cin >> v[i].val;
		v[i].orig_idx = i + 1;
	}

	std::sort(v.begin(), v.end(), [](Val& A, Val& B) {
			return A.val < B.val;
		}
	);

	bool done = false;

	for (ll i = 0; i < n && !done; i++) {
		ll start = 0, end = v.size() - 1;
		
		/** BS #3 (more like a "gotcha") */
		ll added_to_start = 0;

		while (start <= end && !done) {
			ll mid = (start + end) / 2;
			ll target_val = x - v[i].val;

			LOG("i = " << i << " start = " << mid << " mid = " << mid << " end = " << end);

			if (i == mid) {
				start++;
				added_to_start++;
				continue;
			}

			if (v[mid].val == target_val) {
				cout << v[i].orig_idx << " " << v[mid].orig_idx << "\n";
				done = true;
			} else if (v[mid].val >= target_val) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}

		start -= added_to_start;
	}

	if (!done) {
		cout << "IMPOSSIBLE\n";
	}

	return 0;
}

