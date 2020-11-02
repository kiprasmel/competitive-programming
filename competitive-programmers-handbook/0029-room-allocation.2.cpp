#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

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

struct Cust {
	ll s;
	ll e;
	ll oidx;
	ll roomidx;
};

struct Room {
	ll val;
	ll idx;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	 const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int n;
	scanf("%d", &n);

	vector<Cust> c(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &c[i].s, &c[i].e);
		c[i].oidx = i;
	}

	std::sort(c.begin(), c.end(), [](const Cust& A, const Cust& B) {
		/*
		return A.e < B.e;
		*/

		return A.e != B.e
			? A.e < B.e
			: A.s < B.s
		;
	});

	ll max_rooms = 0;

	deque<Room> rooms;

	// ll ridx = 1;

	for (Cust& cust : c) {
		// // vector<ll>::iterator r = std::lower_bound(rooms.begin(), rooms.end(), cust.s);

		// // if (r != rooms.end()) {
		// // 	(*r) = cust.e;
		// // } else {
		// // 	rooms.push_back(cust.e);
		// // }

		// if (rooms.size() && cust.s > rooms.front().val) {
		// 	rooms.pop_front();

		// 	cust.roomidx = ridx;
		// 	ridx++;

		// 	rooms.push_back(cust.e);
		// }  else {
		// 	cust.roomidx = rooms.size() + 1;
		// 	rooms.push_back(cust.e);
		// }

		if (rooms.size() && cust.s > rooms.front().val) {
			cust.roomidx = rooms.front().idx;
			rooms.pop_front();
			rooms.push_back({cust.e, cust.roomidx});
		}  else {
			cust.roomidx = rooms.size() + 1;
			rooms.push_back({cust.e, cust.roomidx});
		}

		max_rooms = max(max_rooms, (ll) rooms.size());
	}

	std::sort(c.begin(), c.end(), [](const Cust& A, const Cust& B) {
		return A.oidx < B.oidx;
	});

	printf("%lld\n", max_rooms);

	for (auto cust : c) {
		printf("%lld ", cust.roomidx);
	}

	return 0;
}
