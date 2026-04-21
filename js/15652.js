let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [N, M] = input[0].split(" ").map((v) => Number(v));

let nums = [];
let result = "";

next(1);

function next(num) {
  if (nums.length === M) {
    result += nums.join(" ") + "\n";
    return;
  }
  for (let n = num; n <= N; n++) {
    nums.push(n);
    next(n);
    nums.pop();
  }
}

console.log(result);
