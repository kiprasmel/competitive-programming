#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#if (0 || defined(DEBUG)) && !defined(PROD)
#define LOG(x) std::cout << x << "\n"
#define LOGS(x) std::cout << x << " "
#else
#define LOG(x)
#define LOGS(x)
#endif

const int n = 8;

void __how_many_times_can_place_queens(ull y, ull& count, std::function<bool (int x, int y)> is_spot_taken, function<void (int x, int y)> take_spot, function<void (int x, int y)> free_spot) {
	if (y == n) {
		count++;
		return;
	}

	for (int x = 0; x < n; x++) {
		if (is_spot_taken(x, y)) {
			continue;
		}

		take_spot(x, y);

		__how_many_times_can_place_queens(y + 1, count, is_spot_taken, take_spot, free_spot);
		
		free_spot(x, y);
	}
}

ull how_many_times_can_place_queens(vector<vector<bool>> is_blocked) {
	vector<bool> column(n);
	vector<bool> row(n);
	vector<bool> diagTL(n);
	vector<bool> diagBL(n);

	ull count = 0;

	auto is_spot_taken = [&] (int x, int y) -> bool {
		return (column[x] || row[y] || diagTL[x+y] || diagBL[x-y+n-1] || is_blocked[x][y]);
	};

	auto take_spot = [&] (int x, int y) -> void {
		column[x] = 1;
		row[y] = 1;
		diagTL[x+y] = 1;
		diagBL[x-y+n-1] = 1;
	};

	auto free_spot = [&] (int x, int y) -> void {
		column[x] = 0;
		row[y] = 0;
		diagTL[x+y] = 0;
		diagBL[x-y+n-1] = 0;
	};

	__how_many_times_can_place_queens(0, count, is_spot_taken, take_spot, free_spot);

	return count;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);

	vector<vector<bool>> is_blocked(n, vector<bool>(n));

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			char tmp;
			cin >> tmp;

			is_blocked[x][y] = !!(tmp != '.');
		}
	}

	cout << how_many_times_can_place_queens(is_blocked) << "\n";

	return 0;
}

