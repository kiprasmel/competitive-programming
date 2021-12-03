#!/usr/bin/env node
let s = require("fs").readFileSync(0).toString();

let ls = s.split("\n").slice(0, -1)
console.log({ls});
console.log(ls[ls.length - 1])
console.log({lslast: ls.slice(-1)})

let len = ls[0].length;

let gamma = new Array(len).fill(0);
let eps = new Array(len).fill(0);

for (let i = 0; i < len; i++) {
	let par = 0;
	for (let j = 0; j < ls.length; j++) {
		par += Number(ls[j][i]) || -1;
	};
	gamma[i] = par > 0 ? 1 : 0;
	eps[i] = par > 0 ? 0 : 1;
	console.log({par, gamma_i: gamma[i], eps_i: eps[i] });
};

let g = eval(`0b${gamma.join("")}`)
let e = eval(`0b${eps.join("")}`)
let m = g * e;

console.log({gamma}, gamma.join(""), {g, e, m});



