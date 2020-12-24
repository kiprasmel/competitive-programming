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
 
/**
 * returns the smallest nonnegative integer
 * that does not belong in the set
 *
 * ~~the set is always sorted increasingly
 * so the implementation just works~~
 *
 * using a vector & sorting once is faster
 * because of better constant factors
 *
*/
// int mex(set<int> grundies) {
int mex(vector<int> grundies) {
	std::sort(grundies.begin(), grundies.end());
 
	int expected = 0;
 
	for (auto g : grundies) {
		if (g != expected) {
			return expected;
		}
 
		expected++;
	}
 
	int biggest_grundy = *grundies.rbegin();
	return biggest_grundy + 1;
}
 
constexpr int mxN = 1e6 + 1;
bool ready[mxN];
int memo_grundy[mxN];
 
int grundy(vector<int> moves, int position) {
	if (ready[position]) {
		return memo_grundy[position];
	}
 
	auto memo = [&](int computed) {
		ready[position] = true;
		memo_grundy[position] = computed;
		return computed;
	};
	
	if (position <= 0) return memo(0);
 
	// set<int> descendand_grundies;
	vector<int> descendand_grundies;
	for (auto move : moves) {
		if (position - move < 0) {
			/** we cannot move lower than 0 */
			continue;
		}
		
		// descendand_grundies.insert(
		descendand_grundies.push_back(
			grundy(moves, position - move)
		);
	}
 
	return memo(mex(descendand_grundies));
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	// const char* __fin  = "in" ; freopen(__fin , "r", stdin ); assert(std::ifstream(__fin).good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);
 
	int n, k;
	cin >> n >> k;
 
	int max_move = -INF;
 
	vector<int> moves(k);
	for (int i = 0; i < k; i++) {
		cin >> moves[i];
		max_move = std::max(max_move, moves[i]);
	}
 
	string s(n + 1, ' ');
	int wins_in_a_row = 0;
	int repeat = 0;
	for (int i = 0; i <= n; i++) {
		int g = grundy(moves, i);
		debug() << imie(i) imie(g);
 
		if (g == 0) {
			s[i] = 'L';
			wins_in_a_row = 0;
		} else {
			s[i] = 'W';
			wins_in_a_row++;
		}
 
		if (wins_in_a_row >= max_move) {
			repeat = i + 1;
			break;
		}
	}
 
	debug() << imie(repeat) imie(s);
	if (repeat != 0) {
		for (int i = 1; i <= n; i++) {
			cout << s[(i) % repeat];
		}
	} else {
		for (int i = 1; i <= n; i++) {
			cout << s[i];
		}
	}
 
	cout << "\n";
 
	return 0;
}
 
