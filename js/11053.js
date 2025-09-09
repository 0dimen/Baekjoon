let fs = require("fs");
// let input = fs.readFileSync("example.txt").toString().split("\n");
let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let N = input[0];
let A = input[1].split(" ");

let maxLs = [];
let maxL = 0;

for (let i = 0; i < A.length; i++) {
  let l = findMax(i);
  if (l > maxL) {
    maxL = l;
  }
}

function findMax(idx) {
  let max = 0;
  for (let i = 0; i < idx; i++) {
    if (parseInt(A[i]) < parseInt(A[idx])) {
      if (max < maxLs[i]) max = maxLs[i];
    }
  }
  maxLs[idx] = max + 1;
  return maxLs[idx];
}

console.log(maxL);
