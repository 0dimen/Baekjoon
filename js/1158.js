let fs = require("fs");
let input = fs.readFileSync("example.txt").toString().split("\n");

let [N, K] = input[0].split(" ").map((v) => Number(v));
let array = [];
let answer = "<";
for (let i = 1; i <= N; i++) {
  array.push(i);
}

let idx = K - 1;
while (array.length > 0) {
  answer += ", " + array[idx];
  array.splice(idx, 1);

  idx = (K + idx - 1) % array.length;
  if (idx < 0) {
    idx += N;
  }
}
answer += ">";
answer = [...answer];
answer.splice(1, 2);

console.log(answer.join(""));
