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

	ll applicant_count, apartment_count, max_diff;
	cin >> applicant_count >> apartment_count >> max_diff;

	vector<ll> applicants(applicant_count);
	for (ll i = 0; i < applicant_count; i++) {
		cin >> applicants[i];
	}

	vector<ll> apts(apartment_count);
	for (ll i = 0; i < apartment_count; i++) {
		cin >> apts[i];
	}

	std::sort(applicants.begin(), applicants.end());
	std::sort(apts.begin(), apts.end());
	
	ll sum = 0;
	ll applic_idx = 0;
	ll apart_idx = 0;
	// for (ll apart_idx = 0; apart_idx < apartment_count && applic_idx < applicant_count; apart_idx++) {
	while (applic_idx < applicant_count && apart_idx < apartment_count) {
		auto& apt = apts[apart_idx];
		auto& applic = applicants[applic_idx];

		long long apart_min = apt - max_diff;
		long long apart_max = apt + max_diff;

		LOG("apart_min, apart_max, applic, apt = " << apart_min << " " <<  apart_max << " " << applic << " " << apt);
		if (applic >= apart_min && applic <= apart_max) {
			applic_idx++;
			apart_idx++;
			sum++;
		}
		else if (applic > apart_max) {
			apart_idx++;
		}
		else if (applic < apart_min) {
			applic_idx++;
		}
	}

	cout << sum << "\n";

	return 0;
}
