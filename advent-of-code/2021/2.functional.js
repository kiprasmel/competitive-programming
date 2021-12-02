#!/usr/bin/env node
let s = require("fs").readFileSync(0).toString();

s.split("\n").slice(0, -1).map(x => x.split(" ")).map(([a, b]) => [a, Number(b)]).reduce(([d, h], [instr, x]) => 
	(
		{
			forward: [d, h + x],
			down: [d + x, h],
			up: [d - x, h],
		}[instr] || [-Infinity, -Infinity]
	),
	[0, 0]
).map((_, __, [d, h]) => d * h).slice(0, 1).map(a => console.log(a))

