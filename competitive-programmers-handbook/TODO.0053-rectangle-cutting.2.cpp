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

bool ready[500][500];
int memo[500][500];

int dp(int a, int b, int d = 0) {
	int f = 1e9;

	if (ready[a][b]) f = memo[a][b];
	else if (a == b) f = 0;
	else if (a == 1) f = b - 1;
	else if (b == 1) f = a - 1;
	// else if 
	else {
		// f = min({ f, dp(a - 1, b) + 1 + dp(1, b), dp(a, b - 1) + 1 + dp(a, 1) });

		for (int i = a; i > floor(a / 2); i--) {
			for (int j = b; j > floor(b / 2); j--) {
				f = min({ f, dp(i - 1, j, d + 1) + 1 + dp(a - (i - 1), j, d + 1), dp(i, j - 1, d + 1) + 1 + dp(i, b - (j - 1), d + 1) });
			}
		}
	}

	ready[a][b] = true;
	ready[b][a] = true;
	memo[a][b] = f;
	memo[b][a] = f;

	LOG("d " << d << "; a " << a << "; b " << b << "; f " << f);

	return f;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in"; freopen(__fin,  "r", stdin); std::ifstream __input_file(__fin); assert(__input_file.good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	int a, b;
	scanf("%d %d", &a, &b);

	int ans = dp(a, b);

	LOG(ans);
	printf("%d", ans);

	return 0;
}
