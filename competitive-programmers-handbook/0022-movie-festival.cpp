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

	int n;
	cin >> n;

	vector<Mov> mov(n);
	for (int i = 0; i < n; i++) {
		cin >> mov[i].s >> mov[i].e;
	}

	std::sort(mov.begin(), mov.end(), [](Mov& A, Mov& B) -> bool {
			return A.e < B.e;
		}
	);

	ll sum = 0;
	ll bussy_till = -1;
	for (Mov& m : mov) {
		if (m.s >= bussy_till) {
			bussy_till = m.e;
			sum++;
		}
	}

	cout << sum << "\n";

	return 0;
}

