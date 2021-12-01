#!/usr/bin/env node
let s = require("fs").readFileSync(0).toString();

s = s.split("\n").map(Number);

let c = 0;
let prev = Infinity;

for (let i = 0; i < s.length; i++) {
	if (s[i] > prev) {
		c++;
	}
	prev = s[i];
}

console.log(c);

