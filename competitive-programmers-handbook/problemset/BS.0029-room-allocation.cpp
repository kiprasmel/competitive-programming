#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF (1e9 + 7)

#if (0 || defined(DEBUG)) && !defined(PROD)
#define LOG(x) std::cout << x << "\n"
#define LOGS(x) std::cout << x << " "
#define LO(x) std::cout << x
#else
#define LOG(x)
#define LOGS(x)
#define LO(x)
#endif

struct Cust {
	ll in;
	ll out;
	ll room_nr;
	ll orig_idx;
	ll orig_room_nr;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//  freopen("in", "r", stdin); std::ifstream __input_file("in"); assert(__input_file.good());
	// freopen("out", "w", stdout);

	ll n;
	cin >> n;

	vector<Cust> c(n);	
	for (ll i = 0; i < n; i++) {
		cin >> c[i].in >> c[i].out;
		c[i].orig_idx = i;
	}

	std::sort(c.begin(), c.end(), [](Cust& A, Cust& B) -> bool {
			// return A.out == B.out ? A.in < B.in : A.out < B.out;
			// return A.in < B.in;
			return A.in == B.in ? A.out < B.out : A.in < B.in;
		}
	);

	for (Cust& cust : c) {
		LOG(cust.in << " " << cust.out);
	}
	LOG("");

	vector<ll> rooms;
	// ll earliest_acail = -INF;

	for (Cust& cust : c) {
		bool found = false;
		// for (ll& taken_till : rooms) {
		for (ull i = 0; i < rooms.size(); i++) {
			ll& taken_till = rooms[i];

			if (cust.in > taken_till) {
				found = true;
				taken_till = cust.out;
				cust.room_nr = i + 1;

				c[cust.orig_idx].orig_room_nr = cust.room_nr;

				break;
			}
		}

		if (!found) {
			rooms.push_back(cust.out);
			cust.room_nr = rooms.size();

			c[cust.orig_idx].orig_room_nr = cust.room_nr;
		}
	}

	cout << rooms.size() << "\n";

	/*
	std::sort(c.begin(), c.end(), [](Cust& A, Cust& B) -> bool {
		return A.orig_idx < B.orig_idx;
	});
	*/

	for (Cust& cust : c) {
		// cout << rooms.size() - cust.room_nr + 1 << " ";
		// cout << cust.room_nr << " ";
		cout << cust.orig_room_nr << " ";
		// cout << rooms.size() - cust.orig_room_nr + 1 << " ";
	}

	return 0;
}
