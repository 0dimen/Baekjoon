let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [n, m] = input[0].split(" ").map((v) => Number(v));

let numbers = Array(n).fill(false);
let array = [];

dfs();
function dfs() {
  if (array.length === m) {
    printArray(array);

    return;
  }

  for (let i = 0; i < n; i++) {
    if (numbers[i] === false) {
      numbers[i] = true;
      array.push(i);
      dfs(i, array);
      numbers[i] = false;
      array.pop();
    }
  }
}

function printArray() {
  console.log(array.map((v) => v + 1).join(" ", (v) => v + 1));
}
