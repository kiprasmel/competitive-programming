#!/usr/bin/env node
let s = require("fs").readFileSync(0).toString();

s.split("\n").map(Number).reduce(([count, prev], curr) =>
	[count + Number(curr > prev), curr],
	[0, Infinity]
).slice(0, 1).map(a => console.log(a));

