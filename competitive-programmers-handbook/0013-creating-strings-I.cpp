#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#if (1 || defined(DEBUG)) && !defined(PROD)
#define LOG(x) std::cout << x << "\n"
#define LOGS(x) std::cout << x << " "
#else
#define LOG(x)
#define LOGS(x)
#endif

ull factorial(ull num) {
	if (num == 0) {
		return 1;
	}

	return num * factorial(num - 1);
}

/* BEGIN generate_permutations */
template<typename T>
vector<vector<T>> __generate_permutations_from(vector<T> items, vector<T>& permutation, unordered_set<int>& chosen) {
	const T& n = items.size();

	if (permutation.size() == n) {
		// process permutation
		return { permutation };
	} else {
		vector<vector<T>> returns;

		for (int i = 0; i < n; i++) {
			T& item = items[i];

			if (chosen.count(i) > 0) {
				continue;
			}

			chosen.insert(i);
			permutation.push_back(item);

			auto ret = __generate_permutations_from(items, permutation, chosen);
			returns.insert(returns.end(), ret.begin(), ret.end());

			chosen.erase(i);
			permutation.pop_back();
		}

		return returns;
	}
}

template<typename T>
/**
 * @example
 * 
 * ```cpp
 * generate_permutations_from({ 'a', 'a', 'b', 'a', 'c' });
 * ```
 */
vector<vector<T>> generate_permutations_from(vector<T> items) {
	vector<T> permutation;
	unordered_set<int> chosen;

	auto ret = __generate_permutations_from(items, permutation, chosen);
	std::sort(ret.begin(), ret.end());
	ret.erase(std::unique(ret.begin(), ret.end()), ret.end());

	return ret;
}
/* END generate_permutations */

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// freopen("in", "r", stdin);
	// freopen("out", "w", stdout);

	string s;
	cin >> s;

	std::sort(s.begin(), s.end());

	vector<char> permutation;
	for (auto c : s) {
		permutation.push_back(c);
	}

	// ull dup_len = s.length();

	// s.erase(std::unique(s.begin(), s.end()), s.end());

	// ull uniq_len = s.length();

	// ull permutation_count = (factorial(dup_len))
	// 						/
	// 						(factorial(dup_len - uniq_len + 1));

	// LOG("\n" << dup_len << " " << uniq_len << " " << s << " " << s.length() << " " << factorial(s.length()) << "\n\n");

	// cout << permutation_count << "\n";

	auto perms = generate_permutations_from(permutation);

	cout << perms.size() << "\n";

	for (auto p : perms) {
		for (auto c : p) {
			cout << c;
		}
		cout << "\n";
	}

	//for (auto perm : generate_permutations_from(permutation, {}, {})) { }
	/**
	int i = 0;
	do {
		LOGS(i++ << " ");
		for (auto c : permutation) {
			cout << c;
		}
		cout << "\n";
	} while (std::next_permutation(permutation.begin(), permutation.end()));
	*/

	return 0;
}
