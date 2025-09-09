let fs = require("fs");
let input = fs.readFileSync("example.txt").toString().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let N = input[0];
let A = input[1].split(" ").map((a) => parseInt(a));

let maxLs = [];
let maxL = 0;

for (let i = 0; i < N; i++) {
  let ls = findMax(i);

  let temp = ls[0] > ls[1] ? ls[0] : ls[1];
  if (temp > maxL) maxL = temp;
}

function findMax(idx) {
  let value = A[idx];
  let incMax = 0;
  let decMax = 0;
  for (let i = 0; i < idx; i++) {
    let inc = maxLs[i][0];
    let dec = maxLs[i][1];
    if (A[i] < value) {
      if (incMax < inc) incMax = inc;
    } else if (A[i] > value) {
      let iDecMax = inc > dec ? inc : dec;
      if (decMax < iDecMax) {
        decMax = iDecMax;
      }
    }
  }

  maxLs[idx] = [incMax + 1, decMax + 1];
  return maxLs[idx];
}

console.log(maxL);
