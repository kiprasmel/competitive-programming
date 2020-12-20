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

constexpr ll  INFLL = 1e18;
constexpr int INF   = 1e9 + 8;
constexpr int MOD   = 1e9 + 7;

// typedef tuple<int, int, int> edge;
typedef pair<ll, ll> pll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in" ; freopen(__fin , "r", stdin ); assert(std::ifstream(__fin).good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int n, m;
	cin >> n >> m;

 	// from, to, weight
	// vector<edge> edges(m);

	vector<vector<pair<int, int>>> adj = vector<vector<pair<int, int>>>(m);


	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		// edges[i] = { a, b, w };
		adj[a].push_back({ b, w });
	}

	vector<ll> distance = vector<ll>(n, INFLL);
	distance[0] = 0;

	vector<bool> visited(n, false);

	// queue<edge> q;
	// {distance, to}
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push({0, 0});

	while (q.size() > 0) {
		// int a = q.front(); q.pop();
		int a = q.top().second; q.pop();

		if (visited[a]) continue;
		visited[a] = true;

		debug() << imie(a+1);

		for (auto [b, w] : adj[a]) {
			if (distance[b] > distance[a] + w) {
				distance[b] = distance[a] + w;
				q.push({distance[b], b});
				// reduced_this_round = true;
			}
		}
	}

	/*
	for (int i = 0; i < n; i++) {
		bool reduced_this_round = false;

		for (auto [a, b, w] : edges) {
			if (distance[b] > distance[a] + w) {
				distance[b] = distance[a] + w;
				reduced_this_round = true;
			}
		}

		if (!reduced_this_round) {
			break;
		}
	}
	*/

	for (int i = 0; i < n; i++) {
		cout << distance[i] << " ";
	}
	
	cout << "\n";

	return 0;
}

