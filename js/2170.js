let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let N = Number(input[0]);
let [start, end] = input[1].split(" ").map((v) => Number(v));
let lines = [];
for (let i = 2; i <= N; i++) {
  let [s, e] = input[i].split(" ").map((v) => Number(v));
  lines.push([s, e]);

  if (s <= end) {
    // s가 start보다 이전인 경우
    if (s < start) {
      start = s;
    }
    if (e > end) {
      end = e;
    }
  }
}

// end와 s가 가까운 순서로 sorting



lines.console.log(Math.abs(end - start) + 1);
