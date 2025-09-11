let fs = require("fs");
let input = fs.readFileSync("example.txt").toString().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let [N, K] = input[0].split(" ").map((v) => Number(v));

let idx = K - 1;
let A = [];
let answer = [];

for (let i = 1; i <= N; i++) {
  A.push(i);
}

while (A.length > 0) {
  answer.push(A.splice(idx, 1));

  idx = (idx + K - 1) % A.length;
}
console.log("<" + answer.join(", ") + ">");
