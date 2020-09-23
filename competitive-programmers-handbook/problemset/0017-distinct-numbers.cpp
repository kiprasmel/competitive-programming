#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#if (1 || defined(DEBUG)) && !defined(PROD)
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

	int n;
	cin >> n;

	vector<ull> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	std::sort(v.begin(), v.end());	

	ull sum = 0;
	ull last_el = 0; // v[i] >= 1
	for (int i = 0; i < n; i++) {
		if (v[i] != last_el) {
			sum++;
		}

		last_el = v[i];
	}

	cout << sum << "\n";

	return 0;
}
