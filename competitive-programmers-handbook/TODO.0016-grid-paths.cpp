#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#if (0 || defined(DEBUG)) && !defined(PROD)
#define LOG(x) std::cout << x << "\n"
#define LOGS(x) std::cout << x << " "
#define LO(x) std::cout << x
#else
#define LOG(x)
#define LOGS(x)
#define LO(x)
#endif

struct Dir {
	char id;
	int dx;
	int dy;
};

const Dir D = { 'D', 0, +1 }, U = { 'U', 0, -1 }, L = { 'L', -1, 0 }, R ={ 'R', +1, 0 };
const vector<Dir> dirs = { D, R, U, L };

struct Solution {
	int n;

	int x;
	int y;

	vector<vector<bool>> visited;

	// DEBUG
	int max_len_so_far;
	int callback_called_times;
	int m_sum;

	Solution() : n(7), x(0), y(0), visited(7, vector<bool>(7, false)),
		max_len_so_far(INT_MIN), callback_called_times(0), m_sum(0)
	{
		visited[0][0] = true;
	}

	bool does_end_up_where_needed(string path) {
		if (!(x == n - 1 && y == n - 1)) {
			return false;
		}

		for (auto row : visited) {
			for (auto i : row) {
				if (!i) {
					return false;
				}
			}
		}

		return true;	
	}

	bool can_go_to_direction(const Dir& dir, char last_dir) {
		if (
				(dir.id == 'U' && last_dir == 'D')
			 || (dir.id == 'D' && last_dir == 'U')
			 || (dir.id == 'L' && last_dir == 'R')
			 || (dir.id == 'R' && last_dir == 'L')
		) {
			return false;
		}

		int xx = x + dir.dx;
		int yy = y + dir.dy;
		LOG("\nid " << dir.id << " xx " << xx << " yy " << yy);

		return !!(
				(xx < n && xx >= 0)
			 && (yy < n && yy >= 0)
			 && (!visited[xx][yy])
		);
	}

	void iterate_through_paths(string so_far, string target_path, function<void (string found_path)> callback) {
		max_len_so_far = max(max_len_so_far, (int) so_far.length());
		LOG("max_len, callback_called_times, m_sum, len, so_far == " << max_len_so_far << " " << callback_called_times << " " << m_sum << " " << so_far.length() << " " << so_far);

		vizualize_path(so_far);

		if (
				(so_far.length() >= n * n - 1)
		 	 && (does_end_up_where_needed(so_far))
		) {
			callback_called_times++;
			callback(so_far);
			return;
		}

		if (x == n - 1 && y == n - 1 && !does_end_up_where_needed(so_far)) {
			return;
		}

		for (int i = 0; i < dirs.size(); i++) {
			int prevIdx = ((i - 1) % dirs.size() + dirs.size()) % dirs.size();
			int nextIdx = ((i + 1) % dirs.size() + dirs.size()) % dirs.size();

			const Dir& prev = dirs[prevIdx];
			const Dir& curr = dirs[i];
			const Dir& next = dirs[nextIdx];

			if (
					!can_go_to_direction(curr, curr.id)
				  && can_go_to_direction(prev, curr.id)
				  && can_go_to_direction(next, curr.id)
			) {
				LOG("ULTRA OPT! " << curr.id << " " << can_go_to_direction(curr, curr.id) << "  " << prev.id << " " << can_go_to_direction(prev, curr.id) << "  " << next.id << " " << can_go_to_direction(next, curr.id));
				return;
			} else {
				LOG("NO ULTRA OPT :c " << curr.id << " " << can_go_to_direction(curr, curr.id) << "  " << prev.id << " " << can_go_to_direction(prev, curr.id) << "  " << next.id << " " << can_go_to_direction(next, curr.id));
			}
		}

		for (const Dir& dir : dirs) {
			if (
					(!can_go_to_direction(dir, so_far[so_far.length() - 1]))
			 	 || (target_path[0] != '?' && target_path[0] != dir.id)
			) {
				continue;
			}

			x += dir.dx;
			y += dir.dy;
			visited[x][y] = true;

			iterate_through_paths(so_far + dir.id, target_path.substr(1), callback);

			visited[x][y] = false;
			y -= dir.dy;
			x -= dir.dx;
		}
	}

	void solve(string path_match) {
		int sum = 0;

		iterate_through_paths("", path_match, [&] (string found_path) {
			// LOG("CALLBACK BBY " << found_path);

			for (int i = 0; i < path_match.length(); i++) {
				const char& c = path_match[i];
				bool matches = !!(c == '?' || c == found_path[i]);

				if (matches) {
					sum++;
					m_sum++;

					cout << "sum inc! " << sum << "; path = " << found_path;

					vizualize_path(found_path);
					cout << "\n";
				}
			}
		});

		cout << sum << "\n";
	}

	void vizualize_path(string path) {
		int xx = 0;
		int yy = 0;

		vector<vector<char>> g(n, vector<char>(n));
	
		for (int i = 0; i < path.size(); i++) {
			char& c = path[i];

			for (auto& dir : dirs) {
				if (dir.id != c) {
					continue;
				}

				g[yy][xx] = dir.id;

				xx += dir.dx;
				yy += dir.dy;

				// g[yy][xx] = dir.id;
			}
		}

		// cout << path << "\n";

		string out = "";

		for (auto& row : g) {
			for (char& dir : row) {
				if (!dir) {
					// LO(" ");
					out += " ";
				} else {
					// cout << dir;
					const map<char, string> m = { { 'D', "⬇" }, { 'U', "⬆" }, { 'L', "⬅" }, { 'R', "➡" } };
					string dir_viz = m.at(dir);
					// LO(dir_viz);
					out += dir_viz;
				}
			}
			// LO("\n\r");
			out += "\n\r";
		}
		// LO("\n\r\n\r");
		out += "\n\r\n\r";

		LO(out);
	}

};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("in", "r", stdin); std::ifstream __input_file("in"); assert(__input_file.good());
	// freopen("out", "w", stdout);

	string path;
	cin >> path;

	LOG("path" << path);

	Solution sol;
	sol.solve(path);

	return 0;
}
