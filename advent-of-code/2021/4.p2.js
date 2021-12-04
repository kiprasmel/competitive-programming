#!/usr/bin/env node
const assert = require("assert")

let s = require("fs").readFileSync(0).toString();

let n = s.split("\n\n").length - 1;

// s = s.replace(/ +/g, " ").split("\n\n").join("\n").split("\n").slice(0, -1)
s = s.replace(/ +/g, " ")
// s = s.split("\n\n").join("\n").split("\n").slice(0, -1)
s = s.split("\n\n").map(xs => xs.split("\n"))

console.log({s})

let calls = s.shift()[0].split(",").map(Number)
console.log({calls})

let boards = []
for (let b = 0; b < n; b++) {
	boards[b] = []
	for (let i = 0; i < 5; i++) {

		boards[b][i] = []
		//for (let j = 0; j < 5; j++) {
		boards[b][i] = s[b][i].split(" ").filter(x => !!x).map(Number)
			console.log({b,i, boards_b_i: boards[b][i]})
		//}
		assert(boards[b][i].length === 5)
	};
	console.log("")

	// console.log({s_i: s[b], boards_b: boards[b]})
};

//console.log({boards})

let notWon = new Set(new Array(n).fill(0).map((_, i) => i))

for (let c = 0; c < calls.length; c++) {
	let call = calls[c]

	for (let b = 0; b < n; b++) {

		for (let i = 0; i < 5; i++) {
			for (let j = 0; j < 5; j++) {
				let v = boards[b][i][j]
				if (v === call) {
					boards[b][i][j] = 'x'
				}
			}
		}

		for (let i = 0; i < 5; i++) {
			let matchR = true
			let matchC = true
			for (let j = 0; j < 5; j++) {
				let v = boards[b][i][j]
				let V = boards[b][j][i]

				if (v !== 'x') {
					matchR = false;
				}
				if (V !== 'x') {
					matchC = false
				}
				if (!matchR && !matchC) break
			}

			if (matchR || matchC) {
				notWon.delete(b)

				if (notWon.size === 0) {
					let sum = sumBoard(boards[b])
					let m = sum * call;
					console.error({b, i, boards_b: boards[b], sum, call, m})
					process.exit(0)
				}
			}
		}
	}
}

function sumBoard(board) {
	let sum = 0
	for (let i = 0; i < board.length; i++) {
		for (j = 0; j < board[i].length; j++) {
			let v = board[i][j]
			console.log({v})
			if (v !== 'x') sum += v
		};
	};
	return sum
}

