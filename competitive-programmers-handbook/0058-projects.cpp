#include <algorithm>
#include <sstream>
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

struct Proj {
	ll s, e, r, idx;
	bool done;
};

// const ll mxN = 2 * 1e5 + 1;

unordered_map<string, ll> cache;
ll call_count;

/// assumes the projects are sorted in increasing order by the ending time
ll backtrack(const vector<Proj>& p, ll min_p_idx = 0,  ll min_starting_time = 0, ll curr_reward = 0) {
	const ll n = p.size();
	call_count++;

	if (min_p_idx > n) {
		return 0;
	}

	std::stringstream ss;
	ss << min_p_idx << " " << min_starting_time << " " << curr_reward;
	const string hash = ss.str();

	LOG("hash = " << hash << " ; call_count = " << call_count);

	if (cache.count(hash)) {
		LOG("using cache!");
		return cache[hash];
	}

	/*
	auto next_p = std::upper_bound(p.begin() + (max(0, min_p_idx)), p.end(), min_p_idx, [](Proj& A, Proj& B) -> bool {
		// return A.e < B.e;
		return A.idx < B.idx;
	});
	*/

	ll max_reward = curr_reward;

	// for (ll i = next_p->idx; i < n; i++) {
	for (ll i = min_p_idx; i < n; i++) {
		if (p[i].s < min_starting_time) {
			continue;
		}

		max_reward = max({
			max_reward,
			backtrack(p, i + 1, p[i].e + 1, curr_reward + p[i].r),
			// backtrack(p, i + 1, min_starting_time, curr_reward)
		});

		LOG("local max_reward = " << max_reward);
	}

	cache[hash] = max_reward;

	LOG("max_reward = " << max_reward);

	return max_reward;	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	ll n;
	cin >> n;

	ll last_day = 0;
	vector<Proj> p(n);
	for (ll i = 0; i < n; i++) {
		Proj& x = p[i];
		cin >> x.s >> x.e >> x.r;
		x.done = false;
		last_day = max(last_day, x.e);
	}

	std::sort(p.begin(), p.end(), [](const Proj& A, const Proj& B) {
		return A.e < B.e;
		/*
		return A.e == B.e
			? A.s < B.s
			: A.e < B.e
		;
		*/
	});

	for (ll i = 0; i < n; i++) {
		p[i].idx = i;
	}

	/// greedy
	/*
	ll reward = 0;
	ll day = 0;
	ll proj_idx = 0;
	while (day < last_day && proj_idx < n) {
		Proj& x = p[proj_idx];

		LOG("proj " << x.s << " " << x.e << " " << x.r << " " << x.done);

		// if (x.done) {
		// 	break;
		// }

		if (x.s <= day || x.done) {
			proj_idx++;
			continue;
		}

		day = x.e;
		reward += x.r;
		x.done = true;
		proj_idx++;
	}

	cout << reward << "\n";
	*/

	/// backtrack
	ll reward = backtrack(p, 0, 0, 0);
	cout << reward << "\n";

	return 0;
}

