int best = 0, sum = 0;

for (int i = 0; i < n; i++) {
	sum = max(array[i], array[i] + sum);
	best = max(best, sum);
}

cout << best << "\n";

