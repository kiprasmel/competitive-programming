#include <bits/stdc++.h>
using     namespace std;

struct Dir {
	int dx;
	int dy;

	bool in_bounds(int y, int min_y, int max_y, int x, int min_x, int max_x, int multiplier) const {
		auto [yy, xx] = this->apply(y, x, multiplier);

		return (   xx >= min_x
				&& xx <  max_x
				&& yy >= min_y
				&& yy <  max_y);
	}

	pair<int, int> apply(int y, int x, int multiplier) const {
		int yy = y + (dy * multiplier);
		int xx = x + (dx * multiplier);
		return { yy, xx };
	}
};

const vector<Dir> dirs = { {+1, 0}, {-1, 0}, {0, +1}, {0, -1}, {+1, +1}, {-1, -1}, {+1, -1}, {-1, +1} };

enum Seat {
	empty = 'L',
	occupied = '#',
	ground = '.'
};

struct EpochResult {
	vector<string> new_seats;
	int empty_count;
	int occupied_count;
};

EpochResult epoch(const vector<string>& seats) {
	vector<string> new_seats = seats; /// copy by value

	int row_height = seats.size();
	int col_width  = seats[0].size();

	int empty_count    = 0;
	int occupied_count = 0;

	for (int y = 0; y < row_height; y++) {
		for (int x = 0; x < col_width; x++) {
			const char& seat = seats[y][x];

			if (seat == Seat::ground) {
				continue;
			}

			auto count_seats = [&](const Seat which_seat_to_count) -> int {
				int count = 0;

				for (const Dir& d : dirs) {
					for (int multiplier = 1; multiplier <= std::max(row_height, col_width); multiplier++) {
						if (!d.in_bounds(y, 0, row_height, x, 0, col_width, multiplier)) {
							break;
						}

						auto [yy, xx] = d.apply(y, x, multiplier);
						const char& some_seat = seats[yy][xx];

						if (some_seat == which_seat_to_count) {
							count++;
						}

						if (some_seat != Seat::ground) {
							break;
						}
					}
				}

				return count;
			};

			auto update_seat = [&](const char& seat) -> char {
				int occupied_around_me = count_seats(Seat::occupied);

				if (seat == Seat::empty && occupied_around_me == 0) {
					return Seat::occupied;
				} else if (seat == Seat::occupied && occupied_around_me >= 5) {
					return Seat::empty;
				} else {
					return seat;
				}
			};

			char new_seat = update_seat(seat);
			new_seats[y][x] = new_seat;

			if (new_seat == Seat::occupied) {
				occupied_count++;
			} else if (new_seat == Seat::empty) {
				empty_count++;
			}
		}
	}

	return { new_seats, empty_count, occupied_count };
}

int main() {
	vector<string> seats;
	string line;
	while (getline(cin, line) && line != "") {
		seats.push_back(line);
	}

	int previous_occupied_seats;
	int current_occupied_seats = -1;
	do {
		previous_occupied_seats = current_occupied_seats;

		EpochResult next = epoch(seats);

		seats                  = next.new_seats;
		current_occupied_seats = next.occupied_count;

	} while (previous_occupied_seats != current_occupied_seats);

	cout << current_occupied_seats << "\n";

	return 0;
}

