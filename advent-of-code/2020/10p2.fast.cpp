#include <bits/stdc++.h>
using     namespace std;
typedef   long long  ll;

const ll MIN_REACH_BEHIND = 1;
const ll MAX_REACH_BEHIND = 3;
const ll RANGE_LENGTH     = MAX_REACH_BEHIND - MIN_REACH_BEHIND + 1;

const ll INCREASE_OF_LARGEST_JOLT = 3;

int main() {
	vector<ll> jolt_positions;

	string line;
	while (getline(cin, line) && line != "") {
		ll jolt_pos = std::stoi(line);
		jolt_positions.push_back(jolt_pos);
	}

	std::sort(jolt_positions.begin(), jolt_positions.end());

	ll largest_jolt = jolt_positions.back() + INCREASE_OF_LARGEST_JOLT;

	jolt_positions.push_back(largest_jolt);

	vector<ll> dp(largest_jolt + RANGE_LENGTH, 0); /// dp[position] = how many ways to get here
	dp[0] = 1;                                     /// exactly 1 way to get to the starting position

	/// O(3n) == O(n)
	for (ll jolt_pos : jolt_positions) {
		for (ll i = MIN_REACH_BEHIND; i <= MAX_REACH_BEHIND; i++) {
			ll pos_behind_me = jolt_pos - i;

			if (pos_behind_me >= 0) {
				dp[jolt_pos] += dp[pos_behind_me];
			}
		}
	}

	cout << dp[largest_jolt] << "\n";

	return 0;
}

