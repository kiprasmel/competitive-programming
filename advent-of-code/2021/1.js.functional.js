#!/usr/bin/env node
let s = require("fs").readFileSync(0).toString();

s = s.split("\n").map(Number);

const c = s.reduce(([count, prev], curr) =>
	[count + Number(curr > prev), curr],
	[0, Infinity]
)[0];

console.log(c);

