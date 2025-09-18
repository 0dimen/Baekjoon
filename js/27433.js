let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let N = Number(input[0]);
let answer = 1;
for (let i = 1; i <= N; i++) {
  answer *= i;
}
console.log(answer);
