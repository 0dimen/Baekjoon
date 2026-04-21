let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [N, M] = input[0].split(" ").map((v) => Number(v));

let numbers = [];
let result = "";

comb(0);

function comb(n) {
  for (let i = n + 1; i <= N - M + numbers.length + 1; i++) {
    numbers.push(i);
    if (numbers.length < M) {
      comb(i);
    } else {
      result += numbers.join(" ") + "\n";
    }
    numbers.pop();
  }
}

console.log(result);
