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

struct Period {
	ll s;
	ll e;
	ll m;
	ll prereq_bullets;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll n, k;
	cin >> n >> k;

	vector<Period> v(n);
	for (ll i = 0; i < n; i++) {
		cin >> v[i].s >> v[i].e >> v[i].m;

		ll time_units = v[i].e - v[i].s + 1;
		ll avail_bullets = time_units * k;
		if (avail_bullets >= v[i].m) {
			v[i].prereq_bullets = 0;
		} else {
			v[i].prereq_bullets = v[i].m - avail_bullets;
		}
	}

	v.push_back({INF, INF, 0, 0});

	for (const Period& p : v) {
		LOG(p.s << " " << p.e << " " << p.m << " " << p.prereq_bullets);
	}

	ll bullets_spent = 0;
	ll ammo = k;
	ll leftover_monsters = 0;
	for (ll i = 0; i < n; i++) {
		Period& p = v[i];
		Period& pnext = v[i + 1];

		ll time = p.s;
		leftover_monsters += v[i].m;

		while (time <= pnext.s) {
			time++;

			if (leftover_monsters >= ammo) {
				leftover_monsters -= ammo;
				bullets_spent += ammo;
				ammo = k;
			} else /*if (leftover_monsters > 0)*/ {
				bullets_spent += leftover_monsters;
				ammo -= leftover_monsters;
				leftover_monsters = 0;

				
			// } else {
				if (pnext.prereq_bullets > ammo) {
					bullets_spent += ammo;
					ammo = k;
				}

				time = p.e;
				break;
			}
		}
		
	}

	cout << bullets_spent << "\n";
	
	return 0;
}

