#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Step {
	ll dx;
	ll dy;
};

void test_case() {
	ll y, x;
	cin >> y >> x;


	ll b = 1, a = 1;
	ll i = 1;
	ll num = 1;

	while (a != x && b != y) {
		vector<Step> steps = { {+1, 0}, {0, +i}, {-i, 0}, {0, +1}, {+(i+1), 0}, {0, -(i+1)} };

		for (auto st : steps) {
			if (a == x && b == y) {
				break;
			}

			for (ll g = 0; g < std::abs(st.dx); g++) {
				if (a == x && b == y) {
					break;
				}

				st.dx > 0
					? a++
					: a--;

				num++;
			}

			for (ll g = 0; g < std::abs(st.dy); g++) {
				if (a == x && b == y) {
					break;
				}

				st.dy > 0
					? b++
					: b--;

				num++;
			}

			/*
			a += st.dx;
			b += st.dy;

			num += std::abs(st.dx);
			num += std::abs(st.dy);
			*/
		}

		i += 2;
	}

	/*
		a++;
		b += i;
		a -= i;
		b++;
		a += i;
		b -= i;
	*/


	cout << num << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		test_case();
	}

	return 0;
}

