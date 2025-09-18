let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let n = Number(input[0]);
console.log(fibo(n));

function fibo(n) {
  if (n === 0) {
    return 0;
  } else if (n === 1) {
    return 1;
  }
  return fibo(n - 1) + fibo(n - 2);
}
