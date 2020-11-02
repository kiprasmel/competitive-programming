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

// ll mxN = 1e6 + 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll n;
	cin >> n;
	vector<ll> v (n);
	ll sum_of_coins = 0;

	for (ll i = 0; i < n; i++) {
		cin >> v[i];
		sum_of_coins += v[i];
	}

	sort(v.rbegin(), v.rend());
	LOGSA(v);
	LOG("");

	vector<ll> possible(sum_of_coins + 1);

	ll possible_count = 0;

	for (ll i = 0; i <= sum_of_coins; i++) {
		LOGSA(possible);
		LOG("");
		for (auto c : v) {
			if (i == 0 || possible[i]) {
				LOG("i = " << i << "; c = " << c << "; i + c = " << i + c << "; possible[i] = " << possible[i] << " ; possible[i + c] = " << possible[i + c]);
				if (possible[i + c] != possible[i] + c) {
					possible_count++;
				}

				possible[i + c] = max(possible[i + c], possible[i] + c);
			} else {
				break;
			}
		}
		LOG("");
	}

	for (ll i = 1; i <= sum_of_coins; i++) {
		if (possible[i] != 0) {
			cout << possible[i] << " ";
		}
	}

	LOG("\n\n");
	cout << possible_count << "\n";


	return 0;
}

