let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let N = Number(input[0]);

let list = [];
let nums = new Map();
for (let i = 1; i <= N; i++) {
  let n = Number(input[i]);
  list.push(n);

  let num = nums.get(n);

  if (num !== undefined) {
    nums.set(n, num + 1);
  } else {
    nums.set(n, 1);
  }
}

list.sort((a, b) => a - b);
// 산술 평균
let avg = Math.round(list.reduce((a, b) => a + b) / N);
if (avg === -0) {
  avg = 0;
}
console.log(avg);
// 중앙값
console.log(list[Math.ceil(N / 2) - 1]);
// 최빈값
nums = [...nums].sort((a, b) => (b[1] === a[1] ? a[0] - b[0] : b[1] - a[1]));

if (nums.length > 1) {
  if (nums[0][1] === nums[1][1]) {
    console.log(nums[1][0]);
  } else {
    console.log(nums[0][0]);
  }
} else {
  console.log(nums[0][0]);
}
// 범위
console.log(list[list.length - 1] - list[0]);
