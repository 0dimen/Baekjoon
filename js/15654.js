let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [N, M] = input[0].split(" ").map((v) => Number(v));

let num = input[1].split(" ").map((v) => Number(v));
num.sort((a, b) => a - b);
let nums = [];
// 조합 P
let result = "";

comb();

function comb() {
  if (nums.length === M) {
    result += nums.join(" ") + "\n";
    return;
  }
  for (let i = 0; i < num.length; i++) {
    nums.push(num[i]);
    num.splice(i, 1);
    comb();
    num.splice(i, 0, nums.pop());
  }
}

console.log(result);
