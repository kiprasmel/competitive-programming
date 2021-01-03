#pragma  GCC optimize     ("O3")
#pragma  GCC target     ("sse4")

#if (0 || defined(DEBUG)) && !defined(EVAL)  && 0
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

/** BEGIN HASH */
struct Hash {
	string s;
	ll A;
	ll B;
	vector<ll> hashes;
	vector<ll> powers;

	Hash(string s, ll A, ll B)
		: s(s), A(A), B(B), hashes(Hash::hash_chars(s, A, B)), powers(Hash::power_chars(s, A, B))
	{
	}

	ll get_hash_in_range(int a, int b) const {
		if (a == 0) return (hashes[b] % B);

		ll ret = ((((hashes[b] - (hashes[a - 1] * powers[b - a + 1])) % B) + B * B) % B);
		debug() << imie(a) imie(b) imie(hashes[b]) imie(hashes[a - 1]) imie(powers[b-a+1]) imie(ret);

		return ret;
	}

	bool contains(const Hash& other, int starting_index) const {
		assert(s.size() >= other.s.size());

		ll my_ranged_hash    = (*this).get_hash_in_range(starting_index, starting_index + other.s.size() - 1);
		ll other_ranged_hash =   other.get_hash_in_range(0             ,                  other.s.size() - 1);

		return (my_ranged_hash == other_ranged_hash);
	}

	static vector<ll> hash_chars(string s, ll A, ll B) {
		vector<ll> hashes(s.size());
		hashes[0] = s[0];

		for (size_t i = 1; i < s.size(); i++) {
			hashes[i] = (hashes[i - 1] * A + s[i]) % B;
		}

		return hashes;
	}

	static vector<ll> power_chars(string s, ll A, ll B) {
		vector<ll> powers(s.size());
		powers[0] = 1;
	
		for (size_t i = 1; i < s.size(); i++) {
			powers[i] = (powers[i - 1] * A) % B;
		}
	
		return powers;
	}
};

auto hash_with(ll A, ll B) {
	return [=] (string s) -> Hash {
		return { s, A, B };
	};
}
/** END HASH */

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// const char* __fin  = "in" ; freopen(__fin , "r", stdin ); assert(std::ifstream(__fin).good());
	// const char* __fout = "out"; freopen(__fout, "w", stdout);

	string str, pattern;
	cin >> str >> pattern;

	if (str.length() < pattern.length()) {
		cout << "0\n";
		return 0;
	}

	auto hasher1 = hash_with(911382323, 972663749);

	Hash h1_str = hasher1(str);
	Hash h1_pattern = hasher1(pattern);

	auto hasher2 = hash_with(971387797, 972453749);

	Hash h2_str = hasher2(str);
	Hash h2_pattern = hasher2(pattern);

	int count = 0;
	for (size_t i = 0; i < str.size() - pattern.size() + 1; i++) {
		if (   h1_str.contains(h1_pattern, i)
		    && h2_str.contains(h2_pattern, i)
		   ) {
			count++;
		}
	}

	cout << count << "\n";

	return 0;
}

