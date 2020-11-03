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

void test_case() {
	ll dmg, heal, healtimes, cooldown;
	cin >> dmg >> heal >> healtimes >> cooldown;

	ll max_dmg = 0;
	ll prev_max_dmg = -INF;

	ll curr_dmg = 0;
	ll curr_heal = 0;

	ll curr_cd = 0;

	queue<ll> heal_ending_times;

	const ll max_heal = heal * healtimes / cooldown;

	ll time = 0;

	ll i = 0;
	// while (i++ < 10) {
	// while (prev_max_dmg != max_dmg) {
	while (i < healtimes + 2) {
		bool add_heal = false;

		if (curr_cd == 0) {
			curr_dmg += dmg;
			curr_cd = cooldown + 1;
			add_heal = true;
		}
		curr_cd--;
		
		ll heals = heal_ending_times.size() * heal;
		LOG("heals " << heals);
		curr_dmg -= heals;

		prev_max_dmg = max_dmg;
		max_dmg = max(max_dmg, curr_dmg);

		if (prev_max_dmg == max_dmg) {
			i++;
		}

		while (heal_ending_times.size() > 0) {
			ll front = heal_ending_times.front();

			if (front <= time) {
				heal_ending_times.pop();
			} else {
				break;
			}
		}

		LOG("add_heal " << add_heal);
		if (add_heal) {
			heal_ending_times.push(time + healtimes);
		}

		LOG("max_dmg " << max_dmg);

		time++;
	}

	cout << max_dmg << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll t;
	cin >> t;

	while (t--) {
		test_case();
	}

	return 0;
}

