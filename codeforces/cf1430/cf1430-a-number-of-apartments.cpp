#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = (1e9 + 7);

#if (0 || defined(DEBUG)) && !defined(EVAL)
#define LOG(x) std::cout << x << "\n"
#define LOGS(x) std::cout << x << " "
#define LO(x) std::cout << x
#define LOGA(x) for (const auto& y : x) { LOG(y); }
#define LOGSA(x) for (const auto& y : x) { LOGS(y); }
#define LOA(x) for (const auto& y : x) { LO(y); }
#else
#define LOG(x)
#define LOGS(x)
#define LO(x)
#define LOGA(x)
#define LOGSA(x)
#define LOA(x)
#endif

struct Ret {
	bool solved;
	ll a;
	ll b;
	ll c;
};

map<string, Ret> cache;

// true -> done; false -> continue;
Ret solve(ll n, ll a, ll b, ll c) {
	if (n < 0) {
		return { false, a, b, c };
	}
	if (n == 0) {
		return { true, a, b, c };
	}
	string hash = "" + to_string(n) + to_string(a) + to_string(b) + to_string(c);
	if (cache.count(hash) > 0) {
		return cache[hash];
	}

	Ret r1 = solve(n - 3, a + 1, b    , c    );
	Ret r2 = solve(n - 5, a    , b + 1, c    );
	Ret r3 = solve(n - 7, a    , b    , c + 1);

	if (r1.solved) {
		cache[hash] = r1;
		return r1;
	}
	if (r2.solved) {
		cache[hash] = r2;
		return r2;
	}
	if (r3.solved) {
		cache[hash] = r3;
		return r3;
	}

	Ret bad = {false, a, b, c};
	cache[hash] = bad;
	
	return bad;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll t;
	cin >> t;

	while (t--) {
		ll n;
		cin >> n;
		LOG("n" << n);

		cache.clear();

		Ret sol = solve(n, 0, 0, 0);

		if (sol.solved) {
			cout << sol.a << " " << sol.b << " " << sol.c << "\n";
		} else {
			cout << (-1) << "\n";
		}
		
	}

	return 0;
}

