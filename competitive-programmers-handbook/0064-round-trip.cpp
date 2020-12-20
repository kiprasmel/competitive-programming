#pragma  GCC optimize     ("O3")
#pragma  GCC target     ("sse4")

#if (0 || defined(DEBUG)) && !defined(EVAL)
	#include "debug.h" // https://github.com/kiprasmel/debug.h
#else
	struct debug {
		template <class c> debug& operator <<(const c&) { return * this; } };
	#define imie(...) ""
#endif

/* BEGIN INC_STACK */
#include <cstdio>
#include <sys/resource.h>

void inc_stack(const __rlim_t kStackSize = 1024L/*B*/ * 1024L/*KB*/ * 64L/*MB*/) {
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
}
/* END INC_STACK */

#include         <bits/stdc++.h>
using             namespace std;

typedef           long long  ll;
typedef  unsigned long long ull;

constexpr ll  INFLL = 1e18;
constexpr int INF   = 1e9 + 8;
constexpr int MOD   = 1e9 + 7;

constexpr int REQUIRED_CYCLE_NODE_COUNT = 3;

vector<vector<int>> adj;
vector<int> counts;
vector<int> children;

/** returns the (first) node at which the cycle starts */
int find_good_enough_cycle(int node, int prev_node) {
	debug() << imie(node) imie(prev_node) imie(counts[node]) imie(counts[prev_node]);

	for (int child : adj[node]) {
		children[node] = child;

		if (child == prev_node) {
			continue;
		}

		bool is_cycle = counts[child] > 0;
		int cycle_node_count = counts[node] - counts[child] + 1;

		if (counts[child] == 0) {
			counts[child] = counts[node] + 1;
		} 

		debug() << imie(is_cycle) imie(cycle_node_count);

		if (is_cycle && cycle_node_count >= REQUIRED_CYCLE_NODE_COUNT) {
			return node;
		} else if (is_cycle) {
			continue;
		} else {
			int candidate_node = find_good_enough_cycle(child, node);
			if (candidate_node != -1) {
				return candidate_node;
			}
		}
	}

	return -1;
}

vector<int> collect_path_from(vector<int> path, int starting_node, int node, int normalization, bool first_time = true) {
	path.push_back(node + normalization);

	if (node == starting_node && !first_time) {
		return path;
	}

	int child = children[node];
	return collect_path_from(path, starting_node, child, normalization, false);
}

int main() {
	inc_stack(1024 * 1024 * 64);

	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in" ; freopen(__fin , "r", stdin ); assert(std::ifstream(__fin).good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int n, m;
	cin >> n >> m;

	adj.resize(n + 1);
	counts.resize(n + 1);
	children.resize(n + 1);

	vector<pair<int, int>> edges;
	set<int> nodes;

	int min_node = INF;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		edges.push_back({a, b});
		edges.push_back({b, a});

		min_node = std::min({ min_node, a, b });
	}

	debug() << imie(min_node);

	/** guarantee that each node is within the interval [0...n-1] */
	for (auto& e : edges) {
		e.first -= min_node;
		e.second -= min_node;

		debug() << imie(e);

		adj[e.first].push_back(e.second);
		adj[e.second].push_back(e.first);

		nodes.insert(e.first);
		nodes.insert(e.second);

	}

	/** actually do the algorithm now lol */
	for (auto i : nodes) {
		if (counts[i] == 0) {
			counts[i] = 1;
		} else {
			continue;
		}

		int starting_node = find_good_enough_cycle(i, -1);
		debug() << imie(starting_node) imie(counts[starting_node]);

		if (starting_node == -1) {
			continue;
		}

		int count_from_start = counts[starting_node];
		if (count_from_start + 1 >= REQUIRED_CYCLE_NODE_COUNT) {
			vector<int> path = collect_path_from({}, starting_node, starting_node, min_node);

			cout << path.size() << "\n";
			for (auto node : path) {
				cout << node << " ";
			}

			return 0;
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}

