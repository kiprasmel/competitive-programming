#!/usr/bin/env node
const stdin = require("fs").readFileSync(0).toString();

const isPassportValid = (passport) => {
	const keyValPairs = passport
							   .trim()
							   .split(/[\s\n\t]+/g)
							   .map(keyVal => keyVal.split(":"));

	const keys = keyValPairs.map(([key]) => key);
	const areKeysValid =     keys.length === 8
					     || (keys.length === 7 && !keys.includes("cid"));

	const isValueValid = (key, valStr, val) => ({
			"byr": valStr.length === 4 && val >= 1920 && val <= 2002,
			"iyr": valStr.length === 4 && val >= 2010 && val <= 2020,
			"eyr": valStr.length === 4 && val >= 2020 && val <= 2030,
			"hgt": (() => {
				const re = /^(\d+)(cm|in)$/;
				const [_, numStr, sizeStr] = valStr.match(re) || [];
				const size = parseInt(numStr);

				return re.test(valStr) &&
					(sizeStr === "cm"
							? size >= 150 && size <= 193
							: sizeStr === "in"
								? size >= 59 && size <= 76
								: false
					   )
			})(),
			"hcl": /#[0-9a-f]{6}$/.test(valStr),
			"ecl": ["amb", "blu", "brn", "gry", "grn", "hzl", "oth"].includes(valStr),
			"pid": /^[0-9]{9}$/.test(valStr),
			"cid": true
		}[key] || false
	);

	const areValuesValid = keyValPairs
									 .every(([key, valStr]) => isValueValid(key, valStr, parseInt(valStr)))

	return areKeysValid && areValuesValid;
}

const countValidPassports = (input) =>
	input
		.split("\n\n")
		.reduce(
			(accum, passport) =>
				accum + isPassportValid(passport),
				0
		);

const ret = countValidPassports(stdin);
console.log(ret);

