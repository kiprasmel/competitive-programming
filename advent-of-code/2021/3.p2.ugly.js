#!/usr/bin/env node
let s = require("fs").readFileSync(0).toString();

let ls = s.split("\n").slice(0, -1)

const lso = ls;

let len = ls[0].length;

let oxy = new Array(len).fill(0);
let co2 = new Array(len).fill(0);

let oxyhas = new Set(new Array(ls.length).fill(0).map((_, i) => i));
console.log({oxyhas})

for (let i = 0; i < len; i++) {

	let par = 0;
	for (let j = 0; j < ls.length; j++) {
		if (!oxyhas.has(j)) continue;

		par += Number(ls[j][i]) || -1;
	};

	for (let j = 0; j < ls.length; j++) {
		if (!oxyhas.has(j)) continue;

		if (oxyhas.size === 1) {
			const idx = [...oxyhas.values()][0]
			oxy = ls[idx];
			break;
		}
		else if (oxyhas.size === 2 && !par) {
			const idxs = [...oxyhas.values()]
			// console.log("oxyhas.sz = 2", {idxs}, ls[idxs[0]][i], ls[idxs[1]][i]);
			oxy = ls[idxs[0]][i] === 1 ? ls[idxs[0]] : ls[idxs[1]]
			break;
		}

		let num = Number(ls[j][i]);
		if (par >= 0) {
			if (num !== 1) {
				oxyhas.delete(j)
			}
		}
		else if (par < 0) {
			if (num !== 0) {
				oxyhas.delete(j)
			}
		}
	};

};

console.log({oxy})

ls = lso

let co2has = new Set(new Array(ls.length).fill(0).map((_, i) => i));
console.log({co2has})

for (let i = 0; i < len; i++) {

	let par = 0;
	for (let j = 0; j < ls.length; j++) {
		if (!co2has.has(j)) continue;

		par += Number(ls[j][i]) || -1;
	};

	for (let j = 0; j < ls.length; j++) {
		if (!co2has.has(j)) continue;

		if (co2has.size === 1) {
			const idx = [...co2has.values()][0]
			co2 = ls[idx];
			break;
		}
		else if (co2has.size === 2 && !par) {
			const idxs = [...co2has.values()]
			co2 = ls[idxs[0]][i] === 1 ? ls[idxs[0]] : ls[idxs[1]]
			break;
		}

		let num = Number(ls[j][i]);
		if (par >= 0) {
			if (num !== 0) {
				co2has.delete(j)
			}
		}
		else if (par < 0) {
			if (num !== 1) {
				co2has.delete(j)
			}
		}
	};
};

console.log({oxy, co2})

let o = eval(`0b${oxy}`)
let c = eval(`0b${co2}`)
let m = o * c;

console.log({o, c, m});

