#!/usr/bin/env node
const assert = require("assert")

let s = require("fs").readFileSync(0).toString()
assert(s.length, "stdin missing")

const delta = {
	X: -1, // lose
	Y: 0, // draw
	Z: 1, // win
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
const you = ["A", "B", "C"]

const norm = x => (x + you.length) % you.length
const myidx = (opp, me) => norm(you.indexOf(opp) + delta[me])
const my = (opp, me) => you[myidx(opp, me)]
const remap = ([opp, me]) => [opp, my(opp, me)]
const calc = ([opp, me]) => fight[me.charCodeAt(0) - opp.charCodeAt(0)] + lame[me]
const sum = (acc, curr) => acc + curr
s = s.split("\n").slice(0, -1).map(l => l.split(" ")).map(remap).map(calc).reduce(sum, 0)

console.log(s)

