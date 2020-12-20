
/* BEGIN OPERATOR<< */
#include<iostream>

template<typename T>
struct C {
	friend std::ostream& operator<<(std::ostream& out, const T& self) {
		out << self.a << " " << self.b << " " << self.c << " ";
		return out;
	}
}
/* END OPERATOR<< */

