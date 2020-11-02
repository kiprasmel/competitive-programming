#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int n;
	ll x;
	scanf("%d %lld", &n, &x);

	vector<Val> v(n);
	unordered_map<ll, int> m;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i].val);
		v[i].oidx = i;
	}

	std::sort(v.begin(), v.end(), [](Val& A, Val& B) {
		return A.val < B.val;
	});

	for (int i = 0; i < n; i++) {
		m.insert({ v[i].val, i });
	}

	bool done = false;
	vector<int> idxes(3);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}

			ll twosum = v[i].val + v[j].val;
			ll idx = x - twosum;

			LOG("twosum " << twosum << "; idx " << idx << "; m.count(idx) " << m.count(idx));

			if (m.count(idx) > 0) {
				if (m[idx] != i && m[idx] != j) {
					idxes = { i, j, m[idx] };
					done = true;
					goto end;
				}
			}
		}
	}
	end:;

	if (!done) {
		printf("IMPOSSIBLE\n");
	} else {
		for (auto idx : idxes) {
			printf("%d ", v[idx].oidx + 1);
		}
	}

	return 0;
}

