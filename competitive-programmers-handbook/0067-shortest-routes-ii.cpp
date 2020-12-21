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



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in" ; freopen(__fin , "r", stdin ); assert(std::ifstream(__fin).good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);


	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<ll>> adj = vector<vector<ll>>(n, vector<ll>(n, INFLL));

	for (int i = 0; i < m; i++) {
		ll a, b, w;
		cin >> a >> b >> w;
		a--; b--;

		debug() << imie(adj[a][b]) imie(adj[b][a]) imie(w);

		adj[a][b] = std::min(adj[a][b], w);
		adj[b][a] = std::min(adj[b][a], w);
	}

	vector<vector<ll>> distance = vector<vector<ll>>(n, vector<ll>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if      (i == j   ) distance[i][j] = 0;
			else if (adj[i][j]) distance[i][j] = adj[i][j];
			else                distance[i][j] = INFLL;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				distance[i][j] = min(distance[i][j],
									 distance[i][k] + distance[k][j]);
			}
		}
	}

	debug() << imie(distance);

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		ll dist = (distance[a][b] == INFLL) ? (-1) : (distance[a][b]);
		cout << dist << "\n";
	}

	return 0;
}

