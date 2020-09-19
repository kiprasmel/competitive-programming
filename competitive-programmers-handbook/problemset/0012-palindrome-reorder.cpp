#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#if (0 || defined(DEBUG)) && !defined(PROD)
#define LOG(x) std::cout << x << "\n"
#else
#define LOG(x)
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	unordered_map<char, ull> m;

	LOG("begin create map");
	for (auto c : s) {
		m[c]++;
	}
	LOG("end create map");

	ull odd_count = 0;
	ull odd_char_count = 0;
	char odd_char;

	LOG("begin no sol check");
	for (auto [c, count] : m) {
		if (count % 2 != 0) {
			odd_count++;
			odd_char_count = count;
			odd_char = c;

			LOG("new odd char = " << c << "; count = " << odd_char_count);
		}

		if (odd_count > 1) {
			cout << "NO SOLUTION\n";
			return 0;
		}
	}
	LOG("end no sol check");

	string p = "";

	if (odd_count == 1) {
		p += std::string(odd_char_count, odd_char);
	}

	LOG("begin gen");
	for (auto [c, count] : m) {
		if (c == odd_char) {
			continue;
		}

		for (int i = 0; i < count / 2; i++) {
			p = c + p + c;
		}
	}
	LOG("end gen");

	cout << p << "\n";

	LOG("done");

	return 0;
}

