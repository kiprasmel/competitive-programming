#include <algorithm>
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}

	queue<int> q;

	q.push(-1);

	for (int i = 0; i < n; i++) {
		if (A[i] != 0) {
			q.push(i);
		}
	}

	q.push(n);

	ll total_sum = 1;

	int left;
	int right = q.front(); q.pop();

	while (!q.empty()) {
		left = right;
		right = q.front(); q.pop();

		LOG("left " << left << "; right " << right);

		if (right - left == 1) {
			continue; /// next to each other
		}

		auto get_current_sum = [&]() {

		ll current_sum = 0; /// for the interval from left to right

		/// cannot because of `m`
		// if (left == -1 && right == n) {
		// 	current_sum = pow(3, n - 1);
		// } else if (left == -1) {
		// 	
		// }

		/*
		// vector<vector<int>> dists(right - left - 1, vector<int>(3, 0));
		vector<vector<int>> dists(right - left + 1, vector<int>(3, 0));
		
		int i = 1;

		while (left + i < right) {
			for (int prev_dist : { -1, 0, 1 }) {
				for (int dist : { -1, 0, 1 }) {

					int weight = dists[i - 1][prev_dist + 1] + dist;
					// int weight = dists[i - 1][dist + 1] + dist;

					if (
							abs(weight) <= i - left
					 	 && abs(weight) <= right - i
					) {
						sum++;
						sum %= (MOD*3);
					}

					dists[i][dist + 1] = weight;
				}
			}

			i++;
		}
		*/

		// vector<vector<int>> dists(right - left - 1, vector<int>(3, 0));
		// vector<vector<int>> dists(right - left + 1, vector<int>(3, 0));
		vector<int> values, new_values;
		new_values.push_back(A[left]); // TODO: A[max(left, 1)]
		
		int i = left + 1; /// distance from left

		while (i < right) {
			values = new_values;
			new_values.clear();

			for (int prev_val : values) {
				LOG("prev_val " << prev_val);
				for (int dir : { -1, 0, 1 }) {

					// int weight = dists[i - 1][dist + 1] + dist;
					// int weight = dists[i - 1][prev_dist + 1] + dist;
					int value = prev_val + dir; /// candidate for A[left + i]

					if (
						/// distance  >=     difference
							i  - left >= abs(value - A[left] )
						 && right - i >= abs(value - A[right])
							
							//abs(abs(value) - A[left])  <= i - left   /// fits by checking distance from left
					 	 //&& abs(abs(value) - A[right]) <= right - i  /// fits by checking distance from right

							//abs(value) <= i /// max distance away
						 && value >= 1 && value <= m /// fits boundaries
					) {
						new_values.push_back(value);

						if (i + 1 == right) {
							/// we're processing leaves (last elements - sum'em up)
							current_sum++;	
							LOG("value " << value << " yes ++");
						} else {
							LOG("value " << value << " yes");
						}
					} else {
						LOG("value " << value << " no");
					}

					// dists[i][dist + 1] = weight;
				}
			}

			i++;
		}

		return current_sum;

		};

		ll csum = 0;

		if (left == -1 && right == n) {
			A.push_back(-1 /** dummy value */);
			A.push_back(-1 /** dummy value */);
			std::rotate(A.rbegin(), A.rbegin() + 1, A.rend()); // rotate by 1 to the right (i.e. {1,2,3,4,-1,-1} -> {-1,1,2,3,4,-1})

			for (int i = 1; i <= m + n + 5; i++) {
				for (int j = 1; j <= m + n + 5; j++) {
					A[0] = i;
					A[n+1] = j;
					csum = max(csum, get_current_sum());
					LOG("i " << i << "; j " << j << "; csum " << csum);
				}
			}
		} else if (left == -1) {

		}

		if (csum != 0) {
			total_sum *= csum;
			total_sum %= MOD;
		}

		LOG("current_sum " << csum << "; total_sum " << total_sum);


	}

	// sum /= 3;
	// sum %= MOD;

	printf("%lld\n", total_sum);

	return 0;
}
