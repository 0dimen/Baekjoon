let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

function decursion(n) {
  if (n === 0) {
    return "-";
  }
  let newStr = decursion(n - 1);
  return newStr + space(n) + newStr;
}

function space(n) {
  return " ".repeat(Math.pow(3, n - 1));
}

for (line of input) {
  let N = Number(line);
  console.log(decursion(N));
}
