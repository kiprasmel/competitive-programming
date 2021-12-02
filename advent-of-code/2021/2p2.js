#!/usr/bin/env node
let s = require("fs").readFileSync(0).toString();

let d = 0;
let h = 0;
let a = 0;

s.split("\n").slice(0, -1).map(x => x.split(" ")).map(([a, b]) => [a, Number(b)]).forEach(([instr, x]) => 
	 ({
		forward: () => (h += x, d += a * x),
		down: () => a += x,
		up: () => a -= x,
	}[instr]())
);

const m = d * h;

console.log({ d, h, m, a })

