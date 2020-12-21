#pragma  GCC optimize     ("O3")
#pragma  GCC target     ("sse4")
 
#if (0 || defined(DEBUG)) && !defined(EVAL)
	#include "debug.h" // https://github.com/kiprasmel/debug.h
#else
	struct debug {
		template <class c> debug& operator <<(const c&) { return * this; } };
	#define imie(...) ""
#endif
 
#include         <bits/stdc++.h>
using             namespace std;
 
typedef           long long  ll;
typedef  unsigned long long ull;
 
constexpr ll  INFLL =  1e18 + 8;
constexpr int INF   =  1e9  + 8;
constexpr int MOD   =  1e9  + 7;

vector<vector<pair<ll, ll>>> adj;
 
vector<ll> visited;
unordered_set<ll> can_reach_end;
void populate_end_reachers(int start, int end) {
	debug() << imie(start) imie(end) imie(adj[start]) imie(can_reach_end);

	if (visited[start]) {
		return;
	}
	visited[start] = true;

	if (start == end) {
		can_reach_end.insert(start);
	}

	for (auto [child, _] : adj[start]) {
		populate_end_reachers(child, end);

		if (can_reach_end.count(child) > 0) {
			can_reach_end.insert(start);
		}
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	// const char* __fin  = "in" ; freopen(__fin , "r", stdin ); assert(std::ifstream(__fin).good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);
 
	int n, m;
	cin >> n >> m;

	visited.resize(n);
	adj.resize(n);
 
	vector<tuple<int, int, int>> edges(m);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
 
		edges[i] = { a, b, w };

		adj[a].push_back({b, w});
	}

	populate_end_reachers(0, n - 1);
	debug() << imie(can_reach_end);
 
	vector<ll> scores(n, -INFLL);
	scores[0] = 0;
	for (ll i = 0; i <= n; i++) {
		bool increased_this_round = false;
		bool increased_path_towards_end = false;
 
		for (auto e : edges) {
			auto [a, b, w] = e;
 
			if (scores[b] < scores[a] + w) {
				scores[b] = scores[a] + w;

				increased_this_round = true;

				if (can_reach_end.count(b) > 0) {
					increased_path_towards_end = true;
				}
			}
		}
 
		if (i >= n && increased_path_towards_end) {
			cout << -1 << "\n";
			return 0;
		}

		if (!increased_this_round) {
			break;	
		}
	}
 
	debug() << imie(scores);
	cout << scores[n - 1] << "\n";
 
	return 0;
}
 
