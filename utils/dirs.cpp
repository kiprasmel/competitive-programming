
/* BEGIN DIRS */
#include <vector>
#include <tuple>

template<typename T>
struct _Dir {
	T dx;
	T dy;

	bool reachable(T y, T min_y_incl, T max_y_excl, T x, T min_x_incl, T max_x_excl) const {
		T yy, xx;
		std::tie(yy, xx) = this->apply(y, x);

		return (   xx >= min_x_incl && xx < max_x_excl
				&& yy >= min_y_incl && yy < max_y_excl);
	}

	std::pair<T, T> apply(T y, T x) const {
		T yy = y + dy;
		T xx = x + dx;

		return { yy, xx };
	}

};

typedef _Dir<int> Dir;

const std::vector<Dir> dirs = { {+1, 0}, {0, +1}, {-1, 0}, {0, -1} };
const std::vector<Dir> diags = { {+1, +1}, {-1, +1}, {-1, -1}, {+1, -1} };
const std::vector<Dir> dirsdiags = { {+1, 0}, {0, +1}, {-1, 0}, {0, -1}, /**/ {+1, +1}, {-1, +1}, {-1, -1}, {+1, -1} };
/* END DIRS */

