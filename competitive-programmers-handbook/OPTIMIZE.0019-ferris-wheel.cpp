#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("in", "r", stdin); std::ifstream __input_file("in"); assert(__input_file.good());
	// freopen("out", "w", stdout);

	ll n, x;
	cin >> n >> x;

	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	std::sort(v.begin(), v.end());

	ll needed_count = 0;
	vector<ll> taken(n, false);
	for (int i = v.size() - 1; i >= 0; i--) {
		LOG("i = " << i);

		if (taken[i]) {
			continue;
		}

		ll tmp_sum = v[i];
		taken[i] = true;


		ll end = i - 1;
		ll start = 0;

		ll closest_fitting = 0;
		ll closest_fitting_idx = -1;

		/** binary search uh! */
		while (start <= end) {
			ll mid = (end + start) / 2;
			LOG("mid = " << mid);

			if (taken[mid]) {
				LOG("TAKEN MID");
				start++;
				continue;
			}

			if (tmp_sum + v[mid] <= x) {
				start = mid + 1;

				if (v[mid] > closest_fitting) {
					closest_fitting = v[mid];
					closest_fitting_idx = mid;
				}
			} else {
				end = mid - 1;
			}
		}

		if (closest_fitting_idx != -1) {
			tmp_sum += closest_fitting;
			taken[closest_fitting_idx] = true;
		}


		/*
		for (int j = i - 1; j >= 0 && tmp_sum < x; j--) {
			if (i == j || taken[j]) {
				continue;
			}

			if (tmp_sum + v[j] <= x) {
				tmp_sum += v[j];
				taken[j] = true;
				// tmp_seats_taken++;
				break;
			}
		}
		*/

		needed_count++;
	}

	cout << needed_count << "\n";

	return 0;
}
