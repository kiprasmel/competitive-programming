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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll t;
	cin >> t;

	while (t--) {
		ll n, k;
		cin >> n >> k;

		vector<char> s(n);
		for (ll i = 0; i < n; i++) {
			cin >> s[i];
		}

		ll score = 0;

		// find all in-betweens
		for (ll i = 0; i < n - 1; i++) {
			if (s[i] != 'W' || (s[i] == 'W' && s[i + 1] == 'W')) {
				continue;
			}
			
			for (ll j = i + 2; j < n; j++) {
				if (s[j] != 'W') {
					continue;
				}
				
				ll count_of_L = j - i + 1 - 2; // `+ 1`, and exclude the ith & jth via `- 2`, in total `- 1`

				LOG("count_of_L " << count_of_L);
				
				if (k >= count_of_L) {
					// turn Ls to Ws
					k -= count_of_L;

					for (ll x = i; x < j; x++) {
						s[x] = 'W';
					}
				}

				i = j;
			}
		}

		// swap remaining `k` Ls to Ws
		for (char& c : s) {
			if (k > 0) {
				if (c != 'W') {
					c = 'W';
					k--;
					LOG("k--");
				}
			} else {
				break;
			}
		}

		ll sum = s[0] == 'W' ? 1 : 0;

		LO(s[0]);
		for (ll i = 1; i < n; i++) {
			LO(s[i]);

			if (s[i] == 'W') {
				if (s[i - 1] == 'W') {
					sum += 2;
				}
				else {
					sum += 1;
				}
			}
		}
			LOG("");

		cout << sum << "\n";
	}

	return 0;
}

