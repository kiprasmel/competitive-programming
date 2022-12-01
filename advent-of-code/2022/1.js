#!/usr/bin/env node
const assert = require("assert")

let s = require("fs").readFileSync(0).toString()
assert(s.length, "stdin provided")

const sum = (acc, curr) => acc + Number(curr)
const max = (acc, curr) => Math.max(acc, curr)
s = s.split("\n\n").map(e => e.split("\n").reduce(sum, 0)).reduce(max, 0)

console.log(s)

