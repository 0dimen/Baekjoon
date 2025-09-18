let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let N = Number(input[0]);
let S = [];
let B = [];
for (let n = 1; n <= N; n++) {
  let [s, b] = input[n].split(" ").map((v) => Number(v));
  S.push(s);
  B.push(b);
}

let min = Infinity;

for (let i = 1; i <= N; i++) {
  makeArr(i, 0, []);
}

function combi(n, idx, arr) {
  if (n === arr.length) {
    console.log(arr);
    return;
  }
  for (let i = idx; i < N; i++) {
    let newArr = [...arr];
    newArr.push(i);
    makeArr(N, idx, newArr);
  }
}

function calc(arrayIdx) {
  let s = BigInt(1);
  let b = 0;
  for (idx of arrayIdx) {
    s *= BigInt(S[idx]);
    b += B[idx];
  }
  let diff = s - BigInt(b);
  if (diff < 0) {
    diff *= BigInt(-1);
  }
  if (min > diff) min = diff;
}

console.log(min.toString());
