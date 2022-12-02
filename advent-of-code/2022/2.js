#!/usr/bin/env node
const assert = require("assert")

let s = require("fs").readFileSync(0).toString()
assert(s.length, "stdin missing")

const me2u = {
	X: "A",
	Y: "B",
	Z: "C",
}
const lame = {
	A: 1,
	B: 2,
	C: 3,
}
const fight = {
	[-1]: 0,
	[0]: 3,
	[1]: 6,
	//
	[2]: 0, // -1
	[-2]: 6, // +1
}

const remap = ([opp, me]) => [opp, me2u[me]]
const calc = ([opp, me]) => fight[me.charCodeAt(0) - opp.charCodeAt(0)] + lame[me]
const sum = (acc, curr) => acc + curr
s = s.split("\n").slice(0, -1).map(l => l.split(" ")).map(remap).map(calc).reduce(sum, 0)

console.log(s)

