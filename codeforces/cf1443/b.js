const readline = require("readline").createInterface({ input: process.stdin, output: process.stdout });

let t = readline();

while (t--) {
	const [a, b] = readline().split(" ");
	/** @type string */
	let s = readline();

	for (let i = 0; i < s.length; i++) {
		const c = s[i];
		if (c != "0") {
			continue;
		}

		let zeroes = 1;
		for (let j = i; j < s.length; j++) {
			if (s[j] == "0") {
				zeroes++;
			}
		}

		if (zeroes * b < a) {
			for (let j = i; j < j + zeroes; j++) {
				s[j] = "1";
			}
		} else {
			s = s.substring(0, i) + s[i] + s.substring(i + 1);
		}
	}

	const ans = s.split("0").filter((spl) => !!spl).length * a;

	console.log(ans);
}
