#!/usr/bin/env node
let s = require("fs").readFileSync(0).toString();

s = s.split("\n").map(Number);
// s.push(0);
// s.push(0);

let count = 0;
let sum = 0;
let prevsum = Infinity;
for (let i = 0; i < s.length; i++) {
	sum += s[i];
	if (i >= 3) {
		sum -= s[i - 3];
		if (sum > prevsum) {
			count++;
		}
	}
	prevsum = sum;
}

console.log(count);

