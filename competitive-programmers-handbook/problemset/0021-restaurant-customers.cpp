#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#if (1 || defined(DEBUG)) && !defined(PROD)
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

	vector<ll> s(n), e(n);

	for (int i = 0; i < n; i++) {
		cin >> s[i] >> e[i];
	}

	std::sort(s.begin(), s.end());
	std::sort(e.begin(), e.end());

	ll curr_activ = 0, max_activ = 0;
	ll si = 0, ei = 0;

	while (si < n && ei < n) {
		if (s[si] < e[ei]) {
			si++;
			curr_activ++;
		} else if (s[si] > e[ei]) {
			ei++;
			curr_activ--;
		} else /** eq */ {
			si++;
			ei++;
		}

		max_activ = max(max_activ, curr_activ);
	}

	cout << max_activ << "\n";

	return 0;
}

