/**
10 5
46 95
80 90
53 78
77 79
75 94
49 87
35 72
57 69
22 99
64 95

->

57 69
35 72
53 78
77 79
49 87
80 90
75 94 <- should take second
46 95 <- should take first
64 95
22 99

but this don't happen

*/


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

struct Mov {
	ll s;
	ll e;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("in", "r", stdin); std::ifstream __input_file("in"); assert(__input_file.good());
	// freopen("out", "w", stdout);

	ll n, k;
	cin >> n >> k;

	vector<Mov> mov(n);
	for (int i = 0; i < n; i++) {
		cin >> mov[i].s >> mov[i].e;
	}

	std::sort(mov.begin(), mov.end(), [](Mov& A, Mov& B) -> bool {
			return A.e == B.e
				? A.s < B.s
				: A.e < B.e
			;
		}
	);

	for (const Mov& m : mov) {
		LOG(m.s << " " << m.e);
	}
	LOG("");

	ll sum = 0;
	queue<ll> bussyness_till;
	for (ll i = 0; i < n; i++) {
		const Mov& m = mov[i];
		if (bussyness_till.size() < k || m.s >= bussyness_till.front()) {
			if (bussyness_till.size() == k) {
				bussyness_till.pop();
			}
			bussyness_till.push(m.e);

			sum++;
		}
	}

	cout << sum << "\n";

	return 0;
}

