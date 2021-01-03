
/** BEGIN STRING_HASH */

#include <string>
#include <vector>
#include <assert.h>

template<typename T>
struct _Hash {
	std::string s;
	T A;
	T B;
	std::vector<T> hashes;
	std::vector<T> powers;

	_Hash(std::string s, T A, T B)
		: s(s), A(A), B(B), hashes(_Hash::hash_chars(s, A, B)), powers(_Hash::power_chars(s, A, B))
	{
	}

	T get_hash_in_range(int a, int b) const {
		if (a == 0) return (hashes[b] % B);

		T ret = ((((hashes[b] - (hashes[a - 1] * powers[b - a + 1])) % B) + B * B) % B);

		return ret;
	}

	bool contains(const _Hash& other, int starting_index) const {
		assert(s.size() >= other.s.size());

		T my_ranged_hash    = (*this).get_hash_in_range(starting_index, starting_index + other.s.size() - 1);
		T other_ranged_hash =   other.get_hash_in_range(0             ,                  other.s.size() - 1);

		return (my_ranged_hash == other_ranged_hash);
	}

	static auto hash_with(T A, T B) {
		return [=] (std::string s) -> _Hash<T> {
			return { s, A, B };
		};
	}

	static std::vector<T> hash_chars(std::string s, T A, T B) {
		std::vector<T> hashes(s.size());
		hashes[0] = s[0];

		for (size_t i = 1; i < s.size(); i++) {
			hashes[i] = (hashes[i - 1] * A + s[i]) % B;
		}

		return hashes;
	}

	static std::vector<T> power_chars(std::string s, T A, T B) {
		std::vector<T> powers(s.size());
		powers[0] = 1;
	
		for (size_t i = 1; i < s.size(); i++) {
			powers[i] = (powers[i - 1] * A) % B;
		}
	
		return powers;
	}
};

using Hash = _Hash<long long>;

/**
auto hasher1 = Hash::hash_with(911382323, 972663749);
auto hasher2 = Hash::hash_with(971387797, 972453749);

Hash h1s = hasher1("lmao");
Hash h1p = hasher1("l");

Hash h2s = hasher2("lmao");
Hash h2p = hasher1("l");
*/

/** END STRING_HASH */

