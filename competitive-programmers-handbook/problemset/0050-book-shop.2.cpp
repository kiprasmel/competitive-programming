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

struct Book {
	int price;
	int pages;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int n, x;
	scanf("%d %d", &n, &x);

	vector<Book> books(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &books[i].price);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &books[i].pages);
	}

	vector<int> dp(x + 1, 0); // amount of pages at price `x`

	for (Book& b : books) {
		for (int p = x; p >= 0; p--) {
			if (p + b.price <= x) {
				dp[p + b.price]	= max(dp[p + b.price], dp[p] + b.pages);
			}
		}

	}

	LOGSA(dp);

	printf("%d\n", dp[x]);

	return 0;
}

