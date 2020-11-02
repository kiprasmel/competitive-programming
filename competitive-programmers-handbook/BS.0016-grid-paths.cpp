#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

const ll INF = (1e9 + 7);

#if (0 || defined(DEBUG)) && !defined(EVAL)
#define LOG(x) std::cout << x << "\n"
#define LOGS(x) std::cout << x << "\t"
#define LO(x) std::cout << x
#define LOGA(x) for (const auto& y : x) { LOG(y); } cout << "\n";
#define LOGSA(x) for (const auto& y : x) { LOGS(y); } cout << "\n";
#define LOA(x) for (const auto& y : x) { LO(y); } cout << "\n\n"
#else
#define LOG(x)
#define LOGS(x)
#define LO(x)
#define LOGA(x)
#define LOGSA(x)
#define LOA(x)
#endif

struct Dir {
	char d;
	char dd;
	int dx;
	int dy;
};

const vector<Dir> dirs = { {'L', 'R', -1, 0}, {'D', 'U', 0, +1}, {'R', 'L', +1, 0}, {'U', 'D', 0, -1} };

vector<vector<ll>> vc(9, vector<ll>(9));

int gsum = 0;

int solve(string s, int sidx, vector<vector<bool>>& v, int x = 1, int y = 1, char prev = '-')  {
	// LOG("x " << x << "; y " << y << "; sidx " << sidx);

	/*
	if (v[x][y]) {
		return 0;
	}
	v[x][y] = true;
	*/

	if (x < 1 || y < 1 || x > 7 || y > 7) {
		return 0;
	}

	if (sidx == 48) {
		return (x == 1 && y == 7) ? 1 : 0;
	}

	vc[x][y]++;
	// LOG(vc[7][1] << "\t" << gsum);
	for (auto a : vc) {
		LOGSA(a);
	}
	LOG("");


	int sum = 0;

	for (int i = 0; i < dirs.size(); i++) {
		const Dir& d = dirs[i];

		// LOG("pd idx " << (i - 1 + dirs.size()) % dirs.size() << "; nd idx " << (i + 1 + dirs.size()) % dirs.size());

		const Dir& pd = dirs[(i - 1 + dirs.size()) % dirs.size()];
		const Dir& nd = dirs[(i + 1 + dirs.size()) % dirs.size()];

		// LOG("d " << d.d << "; pd " << pd.d << "; nd " << nd.d);

		if (d.dd != prev) {
			// \/
			if (v[x + d.dx][y + d.dy] && !v[x + pd.dx][y + pd.dy] && !v[x + nd.dx][y + nd.dy]) {
				//v[x][y] = false;
				LOG("SKIPPING YO");
				// continue;
				return sum;
			}

			if (s[sidx] == '?' || s[sidx] == d.d) {
				ll xx = x + d.dx;
				ll yy = y + d.dy;

				if (v[xx][yy]) {
					continue;
				}

				v[xx][yy] = true;
				sum += solve(s, sidx + 1, v, x + d.dx, y + d.dy, d.d);
				v[xx][yy] = false;
			}
		}
	}

	//v[x][y] = false;
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	string s;
	cin >> s;

	const int n = 7 + ((1) * 2);

	vector<vector<bool>> visited(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		visited[i][0] = true;
		//visited[i][1] = true;

		visited[0][i] = true;
		//visited[1][i] = true;

		visited[n - 1][0] = true;
		//visited[n - 1][1] = true;

		visited[0][n - 1] = true;
		//visited[1][n - 1] = true;
	}

	int sum = solve(s, 0, visited);

	LOG("");
	cout << sum << "\n";

	return 0;
}

