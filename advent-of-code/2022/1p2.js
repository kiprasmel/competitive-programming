#!/usr/bin/env node
const assert = require("assert")

let s = require("fs").readFileSync(0).toString()
assert(s.length, "stdin provided")

const sum = (acc, curr) => acc + Number(curr)
const desc = (a, b) => b - a
s = s.split("\n\n").map(e => e.split("\n").reduce(sum, 0)).sort(desc).splice(0, 3).reduce(sum)

console.log(s)

