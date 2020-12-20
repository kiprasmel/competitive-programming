#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

const int mxN = 1e5 + 7;
vector<int> adj[mxN];
vector<int> components(mxN, -1);

bool dfs(int node_idx, int comp) {
	if (components[node_idx] != -1) {
		return false;
	}

	components[node_idx] = comp;

	for (auto neigh : adj[node_idx]) {
		dfs(neigh, comp);
	}
	
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); assert(std::ifstream(__fin).good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> component_nodes;
	for (int c = 1; c <= n; c++) {
		bool is_new_component = dfs(c, c);

		if (is_new_component) {
			component_nodes.push_back(c);
		}
	}

	int k = component_nodes.size();

	cout << (k - 1) << "\n";
	for (int i = 1; i < k; i++) {
		cout << component_nodes[i - 1] << " " << component_nodes[i] << "\n";
	}

	return 0;
}

