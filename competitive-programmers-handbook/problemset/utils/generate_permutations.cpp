#include <bits/stdc++.h>
using namespace std;

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
