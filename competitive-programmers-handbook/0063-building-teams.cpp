#pragma  GCC optimize     ("O3")
#pragma  GCC target     ("sse4")

#include         <bits/stdc++.h>
using             namespace std;

typedef           long long  ll;
typedef  unsigned long long ull;

const ll MOD =        (1e9 + 7);

#if (0 || defined(DEBUG)) && !defined(EVAL)
#define LOG(x)   std::cout << x << "\n"
#define LOGS(x)  std::cout << x << " "
#define LO(x)    std::cout << x
#define LOGA(x)  for (const auto& y : x) { LOG(y) ; } cout << "\n"  ;
#define LOGSA(x) for (const auto& y : x) { LOGS(y); } cout << "\n\n";
#define LOA(x)   for (const auto& y : x) { LO(y)  ; } cout << "\n\n";
#else
#define LOG(x)
#define LOGS(x)
#define LO(x)
#define LOGA(x)
#define LOGSA(x)
#define LOA(x)
#endif

const int mxN = 1e5 + 7;
vector<int> adj[mxN];
int teams[mxN];

bool is_bipartite(int node, bool blue) {
	/**
	  * 0 -> not visited yet
	  * 1 -> red
	  * 2 -> blue
	*/
	if (teams[node] != 0) {
		LOG("dupl node " << node << "; teams[node] " << teams[node] << "; blue " << blue);
		if (teams[node] != blue + 1) return false; /** mismatch */
		else                         return true ;
	} else {
		LOG("uniq node " << node << "; teams[node] " << teams[node] << "; blue " << blue);
	}

	teams[node] = blue + 1;

	for (auto v : adj[node]) {
		if (v == node) continue; 

		if (!is_bipartite(v, !blue)) {
			return false;
		}
	}
	
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in" ; freopen(__fin , "r", stdin ); assert(std::ifstream(__fin).good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bool possible = true;
	for (int u = 0; u < n; u++) {
		if (teams[u] != 0) continue;

		bool blue = true; /** color here does not matter since it's a different component if it hasn't yet been visited */
		if (!is_bipartite(u, blue)) {
			possible = false;
			break;
		}
	}

	if (!possible) {
		cout << "IMPOSSIBLE\n";
	} else {
		for (auto t : teams) {
			if (t == 0) break;

			cout << t << " ";
		}

		cout << "\n";
	}

	return 0;
}

