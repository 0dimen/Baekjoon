let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

// 0 : 합집합
// 1 : 집합에 포함되어있는지
let nums;
let T = Number(input[0]);
let lineN = 1;
for (let t = 1; t <= T; t++) {
  let answer = "";
  let [n, m] = input[lineN++].split(" ").map((v) => Number(v));

  nums = [];
  for (let i = 0; i < n; i++) {
    nums.push(-1);
  }

  for (let i = 0; i < m; i++) {
    let [command, a, b] = input[lineN++].split(" ").map((v) => Number(v - 1));

    let rootA = findRoot(a);
    let rootB = findRoot(b);

    if (command === -1) {
      // 합집합
      if (a === b) {
        continue;
      }

      // 같은 값인 경우
      nums[rootA] = rootB;
    } else {
      // 부모 같은지 찾기
      if (rootA === rootB) {
        answer += "1";
      } else {
        answer += "0";
      }
    }
  }
  console.log(`#${t} ${answer}`);
}

function findRoot(n) {
  if (nums[n] === -1) {
    // console.log(n);
    return n;
  } else {
    return findRoot(nums[n]);
  }
}
