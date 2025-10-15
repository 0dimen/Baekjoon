let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let N = Number(input[0]);

let vote = [];

let n = Number(input[1]);
let originNum = n;

for (let i = 2; i <= N; i++) {
  vote.push(Number(input[i]));
}

vote.sort((a, b) => b - a);

while (vote[0] >= n) {
  n++;
  vote[0]--;
  vote.sort((a, b) => b - a);
}

console.log(n - originNum);
